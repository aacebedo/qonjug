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

#ifndef FRENCHVERB_H_
#define FRENCHVERB_H_

#include <string>
#include "conjugation/Verb.h"
#include "conjugation/french/FrenchVerbGroup.h"

namespace qonjug
{

  class FrenchVerb : public qonjug::Verb
  {
  public:
    FrenchVerb(const std::string& radical, const std::string& termination,
        FrenchVerbGroup group);

    virtual
    ~FrenchVerb();

    const std::string&
    getRadical() const;

    const std::string&
    getTermination() const;

    virtual std::string
    toString() const;

    FrenchVerbGroup
    getGroup() const;

    virtual Verb* clone() const ;

  private:
    std::string m_radical;
    std::string m_termination;

    FrenchVerbGroup m_group;

  };
}
/* namespace qonjug */

namespace qonjug
{

  inline const std::string&
  FrenchVerb::getRadical() const
  {
    return m_radical;
  }

  inline const std::string&
  FrenchVerb::getTermination() const
  {
    return m_termination;
  }

  inline FrenchVerbGroup
  FrenchVerb::getGroup() const
  {
    return m_group;
  }

  inline std::string
  FrenchVerb::toString() const
  {
    return m_radical + m_termination;
  }

}
#endif
