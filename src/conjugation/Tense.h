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

#ifndef TENSE_H_
#define TENSE_H_

#include <string>

#include "Clonable.h"

namespace qonjug
{

  class Tense : public Clonable<Tense>
  {
  public:
    Tense(const std::string& name);

    virtual
    ~Tense() = 0;

    bool
    operator<(const Tense& right) const;

    const std::string&
    getName() const;

    virtual Tense* clone() const = 0;

  private:
    std::string m_name;
  };

}

namespace qonjug
{
  inline const std::string&
  Tense::getName() const
  {
    return m_name;
  }

  inline bool
  Tense::operator<(const Tense& right) const
  {
    return m_name < right.m_name;
  }

}

#endif
