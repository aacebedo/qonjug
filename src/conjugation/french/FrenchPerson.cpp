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

#include "conjugation/french/FrenchPerson.h"
#include <stdio.h>
namespace qonjug
{

  FrenchPerson::FrenchPerson(const std::string& pronoun, const Genre& genre,
      const Number& number, const int order) :
      Person(pronoun, genre, number)
  {
    m_order = order;
  }

  FrenchPerson::~FrenchPerson()
  {
  }

  Person*
  FrenchPerson::clone() const
  {
    return new FrenchPerson(*this);
  }

  bool
  FrenchPerson::isLess(const Person& val) const
  {
    bool res = false;
    try
      {
        const FrenchPerson& person = dynamic_cast<const FrenchPerson&>(val);

        res = getOrder() + (getNumber()*6) + getGenre()
            < person.getOrder() + (person.getNumber()*6) + person.getGenre();
      }
    catch (...)
      {
        /// The given mode is not a french mode, thus not comparable.
      }
    return res;
  }

}
