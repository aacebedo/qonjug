/*
 * Tense.h
 *
 *  Created on: 15 mai 2013
 *      Author: aacebedo
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

#endif /* MODE_H_ */
