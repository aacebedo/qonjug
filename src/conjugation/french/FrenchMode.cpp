/*
 * FrenchMode.cpp
 *
 *  Created on: 19 mai 2013
 *      Author: aacebedo
 */

#include "FrenchMode.h"

namespace qonjug
{

  FrenchMode::FrenchMode(const std::string& name, const std::string& prefix,
      bool havePronoun) :
      Mode(name), m_prefix(prefix), m_havePronoun(havePronoun)
  {
  }

  FrenchMode::~FrenchMode()
  {}

} /* namespace qonjug */
