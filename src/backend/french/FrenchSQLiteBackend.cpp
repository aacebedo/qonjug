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

#include <algorithm>
#include <functional>
#include <boost/bind.hpp>
#include <boost/scoped_ptr.hpp>
#include <string.h>
#include <stdio.h>

#include <iostream>
#include <iterator>
#include <algorithm>

#include "FrenchSQLiteBackend.h"
#include "KompexSQLiteDatabase.h"
#include "KompexSQLiteStatement.h"
#include "KompexSQLiteException.h"
#include "conjugation/french/FrenchVerb.h"
#include "conjugation/french/FrenchPerson.h"
#include "conjugation/Conjugation.h"

namespace qonjug
{
  log4cxx::Logger* FrenchSQLiteBackend::LOGGER = log4cxx::Logger::getLogger(
      "qonjug.main");
  std::string FrenchSQLiteBackend::RADICAL_COL = "radical";
  std::string FrenchSQLiteBackend::TERMINATION_COL = "termination";
  std::string FrenchSQLiteBackend::CONJUGATION_COL = "conjugation";
  std::string FrenchSQLiteBackend::GROUP_COL = "grp";
  std::string FrenchSQLiteBackend::PRONOUN_COL = "pronoun";
  std::string FrenchSQLiteBackend::NUMBER_COL = "number";
  std::string FrenchSQLiteBackend::GENRE_COL = "genre";
  std::string FrenchSQLiteBackend::ORDER_COL = "ord";
  std::string FrenchSQLiteBackend::TENSE_COL = "tense";
  std::string FrenchSQLiteBackend::MODE_COL = "mode";
  std::string FrenchSQLiteBackend::AUXTENSE_COL = "aux_tense";
  std::string FrenchSQLiteBackend::HAVEPRONOUN_COL = "have_pronoun";
  std::string FrenchSQLiteBackend::PREFIX_COL = "suffix";

  FrenchSQLiteBackend::FrenchSQLiteBackend(const std::string& dbFilePath)
      throw (std::invalid_argument) :
      SQLiteConjugationBackend(dbFilePath)
  {

    try
      {
        boost::scoped_ptr<Kompex::SQLiteStatement> pSt(
            executeQuery("SELECT * FROM persons;"));
        while (pSt->FetchRow())
          {
            m_availablePersons.push_back(
                new FrenchPerson(pSt->GetColumnString(PRONOUN_COL),
                    fromCharToGenre(pSt->GetColumnString(GENRE_COL).at(0)),
                    fromIntToNumber(pSt->GetColumnInt(NUMBER_COL)),
                    pSt->GetColumnInt(ORDER_COL)));
          }

        pSt.reset(
            executeQuery(
                "SELECT tense,aux_tense FROM mode_tense WHERE aux_tense IS NULL GROUP BY tense ORDER BY ord;"));
        while (pSt->FetchRow())
          {
            m_availableTenses.push_back(
                new FrenchTense(pSt->GetColumnString(TENSE_COL), 0));
          }
        pSt.reset(
            executeQuery(
                "SELECT tense,aux_tense FROM mode_tense WHERE aux_tense IS NOT NULL GROUP BY tense ORDER BY ord;"));
        while (pSt->FetchRow())
          {
            FrenchSQLiteBackend::Tenses::const_iterator itTense = find_if(
                getAvailableTenses().begin(), getAvailableTenses().end(),
                boost::bind(&Tense::getName, _1)
                    == pSt->GetColumnString(AUXTENSE_COL));

            if (itTense != getAvailableTenses().end())
              {
                m_availableTenses.push_back(
                    new FrenchTense(pSt->GetColumnString(TENSE_COL),
                        dynamic_cast<const FrenchTense*>(*itTense)));
              }
          }

        boost::scoped_ptr<Kompex::SQLiteStatement> pSt3(
            executeQuery(
                "SELECT mode,suffix,have_pronoun FROM mode_tense GROUP BY mode ORDER BY ord;"));
        while (pSt3->FetchRow())
          {
            m_availableModes.push_back(
                new FrenchMode(pSt3->GetColumnString(MODE_COL),
                    pSt3->GetColumnString(PREFIX_COL),
                    pSt3->GetColumnInt(HAVEPRONOUN_COL) != 0));
          }
      }
    catch (const Kompex::SQLiteException& e)
      {
        throw std::runtime_error(e.GetString());
      }
    catch (const std::invalid_argument& e)
      {
        throw std::runtime_error(e.what());
      }
  }

  FrenchSQLiteBackend::~FrenchSQLiteBackend()
  {
    for (Modes::iterator it = m_availableModes.begin();
        it != m_availableModes.end(); ++it)
      delete *it;
    for (Tenses::iterator it = m_availableTenses.begin();
        it != m_availableTenses.end(); ++it)
      delete *it;
    for (Persons::iterator it = m_availablePersons.begin();
        it != m_availablePersons.end(); ++it)
      delete *it;

  }

  std::vector<boost::shared_ptr<Verb> >*
  FrenchSQLiteBackend::searchVerb(const std::string& toSearch)
      throw (std::runtime_error)
  {
    std::vector<boost::shared_ptr<Verb> >* res = new std::vector<
        boost::shared_ptr<Verb> >();

    char *sqlStatement =
        sqlite3_mprintf(
            "SELECT radical,termination,grp FROM verbs WHERE radical || termination like '%q%%' ORDER BY radical;",
            toSearch.c_str());
    std::string s(sqlStatement);
    sqlite3_free(sqlStatement);

    try
      {
        boost::scoped_ptr<Kompex::SQLiteStatement> pSt(executeQuery(s));
        while (pSt->FetchRow())
          {
            Verb* p = new FrenchVerb(pSt->GetColumnString(RADICAL_COL),
                pSt->GetColumnString(TERMINATION_COL),
                fromInt(pSt->GetColumnInt(GROUP_COL)));
            boost::shared_ptr<Verb> sp(p);
            res->push_back(sp);
          }
      }
    catch (const Kompex::SQLiteException& e)
      {
        throw std::runtime_error(e.GetString());
      }
    catch (const std::invalid_argument& e)
      {
        throw std::runtime_error("invalid verb group");
      }

    return res;
  }

  FrenchSQLiteBackend::Conjugations*
  FrenchSQLiteBackend::conjugate(const Verb& verb) throw (std::runtime_error)
  {
    Conjugations* res = new Conjugations();

    for (FrenchSQLiteBackend::Modes::const_iterator itMode =
        getAvailableModes().begin(); itMode != getAvailableModes().end();
        ++itMode)
      {
        Conjugations* firstRes = conjugate(verb, **itMode);
        if (firstRes->size() != 0)
          {
            res->insert(res->end(), firstRes->begin(), firstRes->end());
          }
      }
    return res;
  }

  FrenchSQLiteBackend::Conjugations*
  FrenchSQLiteBackend::conjugate(const Verb& verb, const Mode& mode)
      throw (std::runtime_error)
  {

    Conjugations* res = new Conjugations();

    for (FrenchSQLiteBackend::Tenses::const_iterator itTense =
        getAvailableTenses().begin(); itTense != getAvailableTenses().end();
        ++itTense)
      {
        Conjugation* conj = conjugate(verb, mode, **itTense);
        if (conj != 0)
          {
            res->push_back(boost::shared_ptr<Conjugation>(conj));
          }
      }
    return res;
  }

  Conjugation*
  FrenchSQLiteBackend::conjugate(const Verb& verb, const Mode& mode,
      const Tense& tense) throw (std::runtime_error)
  {
    Conjugation* res = 0;
    const FrenchVerb* pVerb = dynamic_cast<const FrenchVerb*>(&verb);
    char *sqlStatement =
        sqlite3_mprintf(
            "SELECT CASE WHEN \
(SELECT aux_tense \
FROM mode_tense WHERE \
conjugations2.mode=mode_tense.mode AND \
mode_tense.mode = conjugations2.mode AND \
conjugations2.tense=mode_tense.tense AND \
mode_tense.tense= conjugations2.tense) IS NOT NULL THEN \
(SELECT conjugations.termination \
FROM conjugations \
WHERE conjugations.mode = conjugations2.mode \
AND conjugations.tense = mode_tense2.aux_tense \
AND verb = verbs.auxiliary \
AND persons.pronoun = conjugations.pronoun) || ' ' || radical || conjugations2.termination \
ELSE radical || conjugations2.termination END  as conjugation, \
conjugations2.pronoun \
FROM verbs, conjugations as conjugations2, persons, mode_tense as mode_tense2 \
WHERE conjugations2.verb = verbs.radical || verbs.termination \
AND conjugations2.pronoun = persons.pronoun \
AND mode_tense2.mode = conjugations2.mode \
AND mode_tense2.tense = conjugations2.tense \
AND conjugation IS NOT NULL \
AND verbs.radical || verbs.termination = '%q' \
AND conjugations2.mode ='%q' \
AND conjugations2.tense = '%q' \
GROUP  BY conjugations2.pronoun \
ORDER BY number,persons.ord;",
            verb.toString().c_str(), mode.getName().c_str(),
            tense.getName().c_str());
    std::string statementString(sqlStatement);
    sqlite3_free(sqlStatement);
    try
      {
        boost::scoped_ptr<Kompex::SQLiteStatement> pSt(
            executeQuery(statementString));
        if (pSt->GetNumberOfRows() != 0)
          {
            Conjugation::VerbalForms* pVForms = new Conjugation::VerbalForms();

            while (pSt->FetchRow())
              {
                FrenchSQLiteBackend::Persons::const_iterator itPerson = find_if(
                    getAvailablePersons().begin(),
                    getAvailablePersons().end(),
                    boost::bind(&Person::getPronoun, _1)
                        == pSt->GetColumnString(PRONOUN_COL));

                if (itPerson != getAvailablePersons().end())
                  {
                    pVForms->insert(std::make_pair<const Person*,std::string>(
                        *itPerson,
                            pSt->GetColumnString(CONJUGATION_COL)));
                  }
              }
            res = new Conjugation(*pVerb, mode, tense, pVForms);
          }
      }
    catch (const Kompex::SQLiteException& e)
      {
        throw std::runtime_error(e.GetString());
      }
    catch (const std::invalid_argument& e)
      {
        throw std::runtime_error("invalid verb group");
      }

    return res;
  }


} /* namespace qonjug */
