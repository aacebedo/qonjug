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

#ifndef QONJUG_FRENCHPERSON_H_
#define QONJUG_FRENCHPERSON_H_

#include "conjugation/Person.h"

namespace qonjug
{
  class FrenchPerson : public Person
  {
  public:
    FrenchPerson(const std::string& pronoun, const Genre& genre,
        const Number& number, const int order);

    virtual
    ~FrenchPerson();

    virtual Person*
    clone() const;

    virtual bool
    isLess(const Person& val) const;

    int
    getOrder() const;

  private:
    int m_order;

  };
}

namespace qonjug
{
  inline int
  FrenchPerson::getOrder() const
  {
    return m_order;
  }
}
#endif
