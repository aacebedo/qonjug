/*
 * FrenchMode.h
 *
 *  Created on: 19 mai 2013
 *      Author: aacebedo
 */

#ifndef FRENCHMODE_H_
#define FRENCHMODE_H_

#include "conjugation/Mode.h"

namespace qonjug
{

  class FrenchMode : public Mode
  {
  public:
    FrenchMode(const std::string& name, const std::string& prefix, bool havePronoun);
    virtual
    ~FrenchMode();

    const std::string&
    getPrefix() const;

    bool
    havePronoun() const;

  private:
    std::string m_prefix;
    bool m_havePronoun;

  };

}

namespace qonjug
{

  inline const std::string&
  FrenchMode::getPrefix() const
  {
    return m_prefix;
  }

  inline bool
   FrenchMode::havePronoun() const
   {
     return m_havePronoun;
   }

}

#endif /* FRENCHMODE_H_ */
