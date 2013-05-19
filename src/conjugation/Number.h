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

#ifndef NUMBER_H_
#define NUMBER_H_
#include <stdexcept>
namespace qonjug
{
  enum Number{
    PLURAL,
    SINGLE,
    NUMBER_NB
  };

  Number fromIntToNumber(const int&) throw (std::invalid_argument);
}


#endif
