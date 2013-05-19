/*
 * Group.h
 *
 *  Created on: 12 mai 2013
 *      Author: aacebedo
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

#endif /* GROUP_H_ */
