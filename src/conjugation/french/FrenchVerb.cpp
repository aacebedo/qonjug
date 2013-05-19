/*
 * Verb.cpp
 *
 *  Created on: 12 mai 2013
 *      Author: aacebedo
 */

#include "conjugation/french/FrenchVerb.h"

namespace qonjug
{
  FrenchVerb::FrenchVerb(const std::string& radical,
      const std::string& termination, FrenchVerbGroup group) :
      m_radical(radical), m_termination(termination), m_group(group)
  {
  }

  FrenchVerb::~FrenchVerb()
  {
  }

  Verb* FrenchVerb::clone() const
  {
    return new FrenchVerb(*this);
  }

} /* namespace qonjug */
