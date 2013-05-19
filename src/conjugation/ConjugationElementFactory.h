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

#ifndef CONJUGATIONELEMENTFACTORY_H_
#define CONJUGATIONELEMENTFACTORY_H_

#include <set>


#include "conjugation/Person.h"
#include "conjugation/Tense.h"
#include "conjugation/Mode.h"

namespace qonjug
{

  class ConjugationElementFactory
  {
  public:
    typedef std::set<Person> Persons;
    typedef std::set<Tense> Tenses;
    typedef std::set<Mode> Modes;

  public:
    virtual
    ~ConjugationElementFactory() = 0;

    virtual const Persons& getAvalaiblePersons() const = 0;

    virtual const Tenses& getAvalaibleTenses() const = 0;

    virtual const Modes& getAvalaibleModes() const = 0;

  };

}
#endif
