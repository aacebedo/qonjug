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

#include "conjugation/Genre.h"

namespace qonjug
{

  Genre
  fromCharToGenre(const char& val) throw (std::invalid_argument)
  {
    Genre res = GENRE_NB;
    switch (val)
      {
    case 'm':
      res = MALE;
      break;
    case 'f':
      res = FEMALE;
      break;
    case 'n':
      res = NONE;
      break;
    default:
      throw std::invalid_argument("");
      }
    return res;
  }

}
