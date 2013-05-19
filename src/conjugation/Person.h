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

#ifndef PERSON_H_
#define PERSON_H_

#include <string>
#include <stdint.h>
#include <algorithm>
#include "conjugation/Genre.h"
#include "conjugation/Number.h"

namespace qonjug
{

  class Person
  {
  public:
    Person(const std::string& pronoun, const Genre& genre, const Number& number,
        const uint8_t order);

    virtual
    ~Person();

    const std::string&
    getPronoun() const;

    const Genre
    getGenre() const;

    const Number
    getNumber() const;

    const uint8_t
    getOrder() const;

    bool
    operator<(const Person& right) const;

  private:
    std::string m_pronoum;
    Genre m_genre;
    Number m_number;
    uint8_t m_order;

  };

}

namespace qonjug
{

  inline const std::string&
  Person::getPronoun() const
  {
    return m_pronoum;
  }

  inline const Genre
  Person::getGenre() const
  {
    return m_genre;
  }

  inline const Number
  Person::getNumber() const
  {
    return m_number;
  }

  inline const uint8_t
  Person::getOrder() const
  {
    return m_order;
  }

  inline bool
  Person::operator<(const Person& right) const
  {
    return m_pronoum < right.m_pronoum;
  }

}
#endif
