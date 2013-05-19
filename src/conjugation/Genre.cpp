/*
 * Tense.cpp
 *
 *  Created on: 15 mai 2013
 *      Author: aacebedo
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

} /* namespace dummycomponent */
