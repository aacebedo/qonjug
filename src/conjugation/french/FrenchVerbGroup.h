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

#ifndef FRENCHVERBGROUP_H_
#define FRENCHVERBGROUP_H_

#include <stdexcept>

namespace qonjug
{
  enum FrenchVerbGroup
  {
    FIRST = 1, SECOND = 2, THIRD = 3, GROUP_NB = 4
  };

  FrenchVerbGroup fromInt(const int& i) throw (std::invalid_argument);

}

#endif
