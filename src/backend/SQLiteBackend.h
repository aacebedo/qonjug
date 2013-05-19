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

#ifndef SQLITEBACKEND_H_
#define SQLITEBACKEND_H_

#include <string>
#include <log4cxx/logger.h>

#include "backend/VerbAccessBackend.h"

namespace Kompex
{
  class SQLiteDatabase;
  class SQLiteStatement;
}

namespace qonjug
{
  class SQLiteBackend : public qonjug::VerbAccessBackend
  {
  private:
    static ::log4cxx::Logger * LOGGER;

  public:
    SQLiteBackend(const std::string& dbFilePath);

    virtual
    ~SQLiteBackend() = 0;

  protected:
    Kompex::SQLiteStatement*
    executeQuery(const std::string& query) throw (std::runtime_error);

  protected:
    std::auto_ptr<Kompex::SQLiteDatabase> m_pDatabase;
  };
}

#endif
