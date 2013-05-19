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

#ifndef VERBACCESSBACKEND_H_
#define VERBACCESSBACKEND_H_

#include <stdexcept>
#include <string>
#include <boost/shared_ptr.hpp>
#include <auto_ptr.h>
#include <vector>
#include <set>

namespace qonjug
{
  class Verb;
  class Conjugation;
  class Person;
  class Mode;
  class Tense;
}

namespace qonjug
{
  class VerbAccessBackend
  {
  public:
    typedef std::vector<boost::shared_ptr<Conjugation> > Conjugations;

  public:

    virtual
    ~VerbAccessBackend() = 0;

    virtual std::vector<boost::shared_ptr<Verb> >*
    searchVerb(const std::string& toSearch) throw (std::out_of_range,
        std::runtime_error) = 0;

    virtual Conjugations*
    conjugate(const Verb& verb) throw (std::out_of_range, std::runtime_error) = 0;

    virtual Conjugations*
    conjugate(const Verb& verb, const Mode& mode) throw (std::out_of_range,
        std::runtime_error) = 0;

    virtual Conjugation*
    conjugate(const Verb& verb, const Mode& mode, const Tense& tense)
        throw (std::out_of_range, std::runtime_error) = 0;

    virtual Conjugation*
    conjugate(const Verb& verb, const Mode& mode, const Tense& tense,
        const Person& person) throw (std::out_of_range, std::runtime_error) = 0;

    virtual const std::set<Person>&
    getAvailablePersons() const = 0;
  };
}

#endif
