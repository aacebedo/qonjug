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

#include "FrenchTense.h"

namespace qonjug
{

  FrenchTense::FrenchTense(const std::string& name, FrenchTense const* auxTense) :
      Tense(name), m_auxTense(auxTense)
  {
  }

  FrenchTense::~FrenchTense()
  {
  }

  Tense*
  FrenchTense::clone() const
  {
    return new FrenchTense(*this);
  }
}
