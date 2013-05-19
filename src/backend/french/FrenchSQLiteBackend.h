/*
 * FrenchSQLiteBackend.h
 *
 *  Created on: 14 mai 2013
 *      Author: aacebedo
 */

#ifndef FRENCHSQLITEBACKEND_H_
#define FRENCHSQLITEBACKEND_H_

#include <string>
#include <log4cxx/logger.h>

#include "backend/SQLiteBackend.h"

#include "conjugation/french/FrenchMode.h"
#include "conjugation/french/FrenchTense.h"

namespace qonjug
{
  class FrenchSQLiteBackend : public SQLiteBackend
  {

  public:
    typedef std::set<Person> Persons;
    typedef std::set<FrenchTense> Tenses;
    typedef std::set<FrenchMode> Modes;

  private:
    static ::log4cxx::Logger * LOGGER;
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
    FrenchSQLiteBackend(const std::string& dbFilePath);

    virtual
    ~FrenchSQLiteBackend();

    std::vector<boost::shared_ptr<Verb> >*
    searchVerb(const std::string& toSearch) throw (std::out_of_range,
        std::runtime_error);

    virtual Conjugations*
    conjugate(const Verb& verb) throw (std::out_of_range, std::runtime_error);

    virtual Conjugations*
    conjugate(const Verb& verb, const Mode& mode) throw (std::out_of_range,
        std::runtime_error);

    virtual Conjugation*
    conjugate(const Verb& verb, const Mode& mode, const Tense& tense)
        throw (std::out_of_range, std::runtime_error);

    virtual Conjugation*
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

/* namespace qonjug */
#endif /* SQLITEBACKEND_H_ */
