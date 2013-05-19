/*
 * Tense.cpp
 *
 *  Created on: 15 mai 2013
 *      Author: aacebedo
 */

#include "conjugation/Number.h"

namespace qonjug
{

  Number
   fromIntToNumber(const int& val) throw (std::invalid_argument)
   {
     Number res = NUMBER_NB;
     switch (val)
       {
     case 1:
       res = SINGLE;
       break;
     case 2:
       res = PLURAL;
       break;
     default:
       throw std::invalid_argument("");
       }
     return res;
   }

} /* namespace dummycomponent */
