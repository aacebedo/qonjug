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

#include "conjugation/french/FrenchVerb.h"

namespace qonjug
{
  FrenchVerb::FrenchVerb(const std::string& radical,
      const std::string& termination, FrenchVerbGroup group) :
      m_radical(radical), m_termination(termination), m_group(group)
  {
  }

  FrenchVerb::~FrenchVerb()
  {
  }

  Verb* FrenchVerb::clone() const
  {
    return new FrenchVerb(*this);
  }

}
