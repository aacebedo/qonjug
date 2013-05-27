/*
 *Copyright (c) 2013 ACEBEDO Alexandre.
 *All rights reserved. This program and the accompanying materials
 *are made available under the terms of the GNU Public License v3.0
 *which accompanies this distribution, and is available at
 *http://www.gnu.org/licenses/gpl.html
 *
 *Contributors:
 *    ACEBEDO Alexandre - initial API and implementation
 */

#ifndef CONJUGATION_H_
#define CONJUGATION_H_

#include <map>
#include "conjugation/Person.h"
#include "conjugation/Tense.h"
#include "conjugation/Mode.h"
#include "conjugation/Verb.h"
#include "Clonable.h"

#include "rendering/Renderable.h"

namespace qonjug
{

  /**
   * Class containing a complete conjugation of a verb with a mode and a tense.
   */
  class Conjugation : public Renderable
  {

  private:
    struct PersonComp {
      bool operator() (const Person* left, const Person* right) const
      {return left->isLess(*right);}
    };;

  public:
    /**
     * Map containing the verbal forms of the conjugation depending on the person.
     */
    typedef std::map<const Person*, std::string,PersonComp> VerbalForms;

  public:
    Conjugation(const Verb& verb, const Mode& mode, const Tense& tense,
        VerbalForms* pVerbalForms);

    virtual
    ~Conjugation();

    const Mode&
    getMode() const;

    const Tense&
    getTense() const;

    const Verb&
    getVerb() const;

    const VerbalForms&
    getVerbalForms() const;

    virtual  void
    render(Renderer * pRenderer) const;

  private:
    Mode* m_pMode;
    Tense* m_pTense;
    Verb* m_pVerb;

    VerbalForms* m_pVerbalForms;
  };
}

namespace qonjug
{
  inline const Mode&
  Conjugation::getMode() const
  {
    return *m_pMode;
  }

  inline  const Tense&
  Conjugation::getTense() const
  {
    return *m_pTense;
  }

  inline const Verb&
  Conjugation::getVerb() const
  {
    return *m_pVerb;
  }

  inline const Conjugation::VerbalForms&
  Conjugation::getVerbalForms() const
  {
    return *m_pVerbalForms;
  }


}
#endif
