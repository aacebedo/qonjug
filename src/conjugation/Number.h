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

#ifndef QONJUG_NUMBER_H_
#define QONJUG_NUMBER_H_

#include <stdexcept>

namespace qonjug
{
  /**
   * Number used by the Person interface.
   */
  enum Number{
    SINGLE=1,
    PLURAL,
    NUMBER_NB
  };

  /**
   * Integer to Number conversion function.
   * @param val the integer to convert.
   * @return The converted number.
   * @throw std::invalid_argument if the given integer cannot be converted to a Number.
   */
  Number fromIntToNumber(const int& val) throw (std::invalid_argument);
}


#endif
