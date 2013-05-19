/*
 * Person.cpp
 *
 *  Created on: 15 mai 2013
 *      Author: aacebedo
 */

#include "conjugation/Person.h"

namespace qonjug
{

  Person::Person(const std::string& pronoun, const Genre& genre,
      const Number& number, const uint8_t order) :
      m_pronoum(pronoun), m_genre(genre), m_number(number), m_order(order)
  {
  }

  Person::~Person()
  {
  }

}
