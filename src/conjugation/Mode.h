/*
 * Mode.h
 *
 *  Created on: 15 mai 2013
 *      Author: aacebedo
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

#endif /* MODE_H_ */
