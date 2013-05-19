/*
 * Number.h
 *
 *  Created on: 15 mai 2013
 *      Author: aacebedo
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


#endif /* NUMBER_H_ */
