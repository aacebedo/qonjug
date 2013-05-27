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

#ifndef FRENCHSQLITEBACKEND_H_
#define FRENCHSQLITEBACKEND_H_

#include <string>
#include <log4cxx/logger.h>

#include "fwd_decls.h"
#include "backend/SQLiteBackend.h"
#include "conjugation/french/FrenchMode.h"
#include "conjugation/french/FrenchTense.h"

namespace qonjug
{
  /**
   * SQLite backend for french language.
   */
  class FrenchSQLiteBackend : public SQLiteBackend
  {

  private:
    static ::log4cxx::Logger * LOGGER;

    /**
     * Static strings representing databases columns.
     */
    static std::string RADICAL_COL;
    static std::string TERMINATION_COL;
    static std::string CONJUGATION_COL;
    static std::string GROUP_COL;
    static std::string PRONOUN_COL;
    static std::string NUMBER_COL;
    static std::string GENRE_COL;
    static std::string ORDER_COL;
    static std::string TENSE_COL;
    static std::string MODE_COL;
    static std::string AUXTENSE_COL;
    static std::string HAVEPRONOUN_COL;
    static std::string PREFIX_COL;

  public:
    /**
     * Default constructor.
     * @param dbFilePath the path to the database containing the french conjugation.
     * @throw invalid_argument when the file path to the database is invalid.
     */
    FrenchSQLiteBackend(const std::string& dbFilePath) throw (std::invalid_argument);

    /**
     * Default destructor.
     */
    virtual
    ~FrenchSQLiteBackend();


    boost::shared_ptr<VerbSearchResult>
    searchVerb(const std::string& toSearch) throw (std::runtime_error);


    virtual  boost::shared_ptr<Conjugations>
    conjugate(const Verb& verb) throw (std::out_of_range, std::runtime_error);

    virtual  boost::shared_ptr<Conjugations>
    conjugate(const Verb& verb, const Mode& mode) throw (std::out_of_range,
        std::runtime_error);

    virtual  boost::shared_ptr<Conjugation>
    conjugate(const Verb& verb, const Mode& mode, const Tense& tense)
        throw (std::out_of_range, std::runtime_error);

    virtual  boost::shared_ptr<Conjugation>
    conjugate(const Verb& verb, const Mode& mode, const Tense& tense,
        const Person& person) throw (std::out_of_range, std::runtime_error);

    virtual const Persons&
    getAvailablePersons() const;

    virtual const Modes&
    getAvailableModes() const;

    virtual const Tenses&
    getAvailableTenses() const;

  private:
    Persons m_availablePersons;
    Tenses m_availableTenses;
    Modes m_availableModes;

  };
}
#endif
