/*
 * ConjugationElementFactory.h
 *
 *  Created on: 15 mai 2013
 *      Author: aacebedo
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

} /* namespace dummycomponent */
#endif /* CONJUGATIONELEMENTFACTORY_H_ */
