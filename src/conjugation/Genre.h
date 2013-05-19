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

#ifndef GENRE_H_
#define GENRE_H_

#include <stdexcept>

namespace qonjug
{
  enum Genre
  {
    NONE,
    FEMALE,
    MALE,
    GENRE_NB
  };

  Genre fromCharToGenre(const char&) throw (std::invalid_argument);
}

#endif
