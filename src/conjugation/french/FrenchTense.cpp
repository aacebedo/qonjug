/*
 * FrenchTense.cpp
 *
 *  Created on: 19 mai 2013
 *      Author: aacebedo
 */

#include "FrenchTense.h"

namespace qonjug
{

  FrenchTense::FrenchTense(const std::string& name, FrenchTense const* auxTense) :
      Tense(name), m_auxTense(auxTense)
  {
  }

  FrenchTense::~FrenchTense()
  {
  }

  Tense*
  FrenchTense::clone() const
  {
    return new FrenchTense(*this);
  }
} /* namespace qonjug */
