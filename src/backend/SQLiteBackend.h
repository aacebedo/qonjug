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

#ifndef QONJUG_SQLITEBACKEND_H_
#define QONJUG_SQLITEBACKEND_H_

#include <string>
#include <log4cxx/logger.h>
#include <boost/shared_ptr.hpp>
#include <stdexcept>

#include "fwd_decls.h"
#include "backend/VerbAccessBackend.h"

namespace qonjug
{
  /**
   * Default SQLite backend.
   */
  class SQLiteBackend : public qonjug::VerbAccessBackend
  {
  private:
    static ::log4cxx::Logger * LOGGER; /// Logger for all operations on SQLite.

  public:
    /**
     * Default constructor
     */
    SQLiteBackend(const std::string& dbFilePath) throw (std::invalid_argument);

    /**
     * Default destructor.
     */
    virtual
    ~SQLiteBackend() = 0;

  protected:
    /**
     * Execute an SQL query on the database.
     * @param query the query to execute.
     * @return a pointer to the SQLiteStatement resulting of the query execution.
     * @throw runtime_error
     */
    boost::shared_ptr<Kompex::SQLiteStatement>
    executeQuery(const std::string& query) throw (std::runtime_error);

  protected:
    std::auto_ptr<Kompex::SQLiteDatabase> m_pDatabase;
  };
}

#endif
