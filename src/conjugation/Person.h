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

#ifndef QONJUG_PERSON_H_
#define QONJUG_PERSON_H_

#include <string>
#include <stdint.h>
#include <algorithm>
#include "Clonable.h"
#include "Comparable.h"
#include "conjugation/Genre.h"
#include "conjugation/Number.h"

namespace qonjug
{
  /**
   * Interface representing the person concept.
   */
  class Person : public Clonable<Person>, public Comparable<Person>
  {
  public:
   /**
    * Constructor
    * @param pronoun the pronoun representing the person.
    * @param genre the person's genre (male, female, none).
    * @param the person's number (singular, plural).
    */
    Person(const std::string& pronoun, const Genre& genre, const Number& number);

    /**
     * Destructor.
     */
    virtual
    ~Person() = 0;

    /**
     * Get the person's pronoun.
     * @return a string representing the pronoun.
     */
    const std::string&
    getPronoun() const;

    /**
     * Get the person's genre.
     * @return the genre.
     */
    const Genre
    getGenre() const;

    /**
     * Get the person's number.
     * @return the number.
     */
    const Number
    getNumber() const;

  private:
    std::string m_pronoum;
    Genre m_genre;
    Number m_number;
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
}
#endif
