/*
 * Genre.h
 *
 *  Created on: 15 mai 2013
 *      Author: aacebedo
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


#endif /* GENRE_H_ */
