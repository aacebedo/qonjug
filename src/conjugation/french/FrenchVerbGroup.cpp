/*
 * Verb.cpp
 *
 *  Created on: 12 mai 2013
 *      Author: aacebedo
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

} /* namespace qonjug */
