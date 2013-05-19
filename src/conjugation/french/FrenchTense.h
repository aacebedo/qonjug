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
    FrenchTense(const std::string& name, FrenchTense const* auxTense);
    virtual
    ~FrenchTense();

    virtual Tense* clone() const;

    FrenchTense const* getAuxTense() const;

  private:
    bool m_haveAux;
    FrenchTense const* m_auxTense;
  };

}

namespace qonjug
{
  inline FrenchTense const* FrenchTense::getAuxTense() const
  {
    return m_auxTense;
  }
}
#endif
