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

#ifndef QONJUG_CONJUGATIONBACKEND_H_
#define QONJUG_CONJUGATIONBACKEND_H_

#include <stdexcept>
#include <string>
#include <boost/shared_ptr.hpp>
#include <vector>

#include "fwd_decls.h"
namespace qonjug
{
  /**
   * Interface for backends used for conjugation.
   */
  class ConjugationBackend
  {
  public:
    /**
     * Public typedefs.
     */
    typedef std::vector<boost::shared_ptr<Verb> > VerbSearchResult;
    typedef std::vector<boost::shared_ptr<Conjugation> > Conjugations;
    typedef std::vector<const Person*> Persons;
    typedef std::vector<const Tense*> Tenses;
    typedef std::vector<const Mode*> Modes;

  public:

    /**
     * Default constructor.
     */
    virtual
    ~ConjugationBackend() = 0;

    /**
     * Search the database for a verb.
     * The created SQL request assumes a LIKE function, it will add a % at the end of the verb to search.
     * @param toSearch the verb to search.
     * @return a pointer to the vector containing the verbs found in the database.
     * If no verb has been found, an empty vector will be returned.
     * @throw runtime_error if something went wrong during the search.
     */
    virtual VerbSearchResult*
    searchVerb(const std::string& toSearch) throw (std::runtime_error) = 0;

    /**
     * Conjugate a verb to all times and all modes.
     * @param verb the verb to conjugate.
     * @return a pointer to a vector containing all the conjugations.
     * If the verb is not found, an empty vector will be returned.
     * @throw runtime_error if something went wrong during the search.
     */
    virtual Conjugations*
    conjugate(const Verb& verb) throw (std::runtime_error) = 0;

    /**
     * Conjugate a verb to all times for a given mode.
     * @param verb the verb to conjugate.
     * @param mode the mode to conjugate.
     * @return a pointer to a vector containing all the conjugations.
     * If the verb is not found, an empty vector will be returned.
     * @throw runtime_error if something went wrong during the search.
     */
    virtual Conjugations*
    conjugate(const Verb& verb, const Mode& mode) throw (std::runtime_error) = 0;

    /**
     * Conjugate a verb for a given mode and a given time.
     * @param verb the verb to conjugate.
     * @param mode the mode to conjugate.
     * @param tense the tense to conjugate.
     * @return a pointer to a vector containing the conjugation.
     * @throw out_of_range if a verb, the mode or the tense is not found.
     * @throw runtime_error if something went wrong during the search.
     */
    virtual Conjugation*
    conjugate(const Verb& verb, const Mode& mode, const Tense& tense)
        throw (std::out_of_range, std::runtime_error) = 0;

    /**
     * Get available persons.
     * @ return a pointer to a vector containing the available persons.
     */
    virtual const Persons&
    getAvailablePersons() const = 0;

    /**
     * Get available modes.
     * @ return a pointer to a vector containing the available modes.
     */
    virtual const Modes&
    getAvailableModes() const = 0;

    /**
     * Get available tenses.
     */
    virtual const Tenses&
    getAvailableTenses() const = 0;
  };
}

#endif
