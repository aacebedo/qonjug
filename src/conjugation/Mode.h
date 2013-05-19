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

#ifndef MODE_H_
#define MODE_H_

#include <string>

namespace qonjug
{

  class Mode
  {
  public:
    Mode(const std::string& name);

    virtual
    ~Mode() = 0;

    const std::string&
    getName() const;

    bool
    operator<(const Mode& right) const;

  private:
    std::string m_name;
  };

}

namespace qonjug
{
  inline const std::string&
  Mode::getName() const
  {
    return m_name;
  }

  inline bool
  Mode::operator<(const Mode& right) const
  {
    return m_name < right.m_name;
  }
}

#endif
