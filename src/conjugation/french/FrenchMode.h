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

#ifndef FRENCHMODE_H_
#define FRENCHMODE_H_

#include "conjugation/Mode.h"

namespace qonjug
{

  class FrenchMode : public Mode
  {
  public:
    FrenchMode(const std::string& name, const std::string& prefix, bool havePronoun);
    virtual
    ~FrenchMode();

    const std::string&
    getPrefix() const;

    bool
    havePronoun() const;

  private:
    std::string m_prefix;
    bool m_havePronoun;

  };

}

namespace qonjug
{

  inline const std::string&
  FrenchMode::getPrefix() const
  {
    return m_prefix;
  }

  inline bool
   FrenchMode::havePronoun() const
   {
     return m_havePronoun;
   }

}

#endif
