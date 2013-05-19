/*
 * SQLiteBackend.h
 *
 *  Created on: 14 mai 2013
 *      Author: aacebedo
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
/* namespace qonjug */
#endif /* SQLITEBACKEND_H_ */
