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

#include <boost/scoped_ptr.hpp>

#include "SQLiteConjugationBackend.h"
#include "KompexSQLiteDatabase.h"
#include "KompexSQLiteStatement.h"
#include "KompexSQLiteException.h"

namespace qonjug
{
  log4cxx::Logger* SQLiteConjugationBackend::LOGGER =
      log4cxx::Logger::getLogger("qonjug.main");

  SQLiteConjugationBackend::SQLiteConjugationBackend(
      const std::string& dbFilePath) throw (std::invalid_argument)
  {
    try
      {
        // open database
        m_pDatabase = new Kompex::SQLiteDatabase(dbFilePath,
            SQLITE_OPEN_READWRITE, 0);
      }
    catch (const Kompex::SQLiteException& e)
      {
        throw std::invalid_argument("Conjugation database not found");
      }
  }

  SQLiteConjugationBackend::~SQLiteConjugationBackend()
  {
    delete m_pDatabase;
  }

  Kompex::SQLiteStatement*
  SQLiteConjugationBackend::executeQuery(const std::string& query)
      throw (std::runtime_error)
  {
    Kompex::SQLiteStatement* res = new Kompex::SQLiteStatement(
        m_pDatabase);
    try
      {
        LOG4CXX_DEBUG(LOGGER, "Execute query: " << query);
        res->Sql(query);
      }
    catch (Kompex::SQLiteException& e)
      {
        delete res;
        throw std::runtime_error(e.GetString());
      }
    return res;
  }
}
