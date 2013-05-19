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
