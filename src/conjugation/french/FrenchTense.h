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

#ifndef FRENCHTENSE_H_
#define FRENCHTENSE_H_

#include "conjugation/Tense.h"

namespace qonjug
{
  class FrenchTense : public Tense
  {
  public:
    FrenchTense(const std::string& name, const FrenchTense* pAuxTense);

    FrenchTense(const FrenchTense& orig);

    virtual
    ~FrenchTense();

    const FrenchTense&
    getAuxTense() const;

    virtual const std::string&
    getName() const;

    virtual Tense*
    clone() const;

    virtual bool
    isLess(const Tense& val) const;

  private:
    std::string m_name;
    FrenchTense * m_pAuxTense;
  };

}

namespace qonjug
{
  inline const FrenchTense&
  FrenchTense::getAuxTense() const
  {
    return *m_pAuxTense;
  }

  inline const std::string&
  FrenchTense::getName() const
  {
    return m_name;
  }

}
#endif
