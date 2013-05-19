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

#include "conjugation/french/FrenchVerbGroup.h"

namespace qonjug
{
  FrenchVerbGroup
  fromInt(const int& i) throw (std::invalid_argument)
  {
    switch (i)
      {
    case 1:
      return FIRST;
    case 2:
      return SECOND;
    case 3:
      return THIRD;
    default:
      throw std::invalid_argument("");
      }
  }

}
