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

#include <vector>
#include "conjugation/Person.h"
#include "conjugation/Tense.h"
#include "conjugation/Mode.h"
#include "conjugation/Verb.h"

#include "rendering/Renderable.h"

namespace qonjug
{

  class Conjugation : public Renderable
  {
  public:
    typedef std::vector<std::pair<Person, std::string> > Terms;

  public:
    Conjugation(const Verb& verb, const Mode& mode, const Tense& tense,
        Terms terms);

    virtual
    ~Conjugation();

    const Mode&
    getMode() const;

    const Tense&
    getTense() const;

    const Verb&
    getVerb() const;

    const Terms&
    getTerms() const;

    virtual void
    render(Renderer * pRenderer) const;

  private:
    const Mode& m_pMode;
    const Tense& m_pTense;
    const Verb* m_pVerb;

    Terms m_terms;
  };
}

namespace qonjug
{
  inline const Mode&
  Conjugation::getMode() const
  {
    return m_pMode;
  }

  inline const Tense&
  Conjugation::getTense() const
  {
    return m_pTense;
  }

  inline const Verb&
  Conjugation::getVerb() const
  {
    return *m_pVerb;
  }

  inline const Conjugation::Terms&
  Conjugation::getTerms() const
  {
    return m_terms;
  }
}
#endif
