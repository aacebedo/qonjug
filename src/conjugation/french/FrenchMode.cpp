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

#include "FrenchMode.h"

namespace qonjug
{

  FrenchMode::FrenchMode(const std::string& name, const std::string& prefix,
      bool havePronoun) :
      m_name(name), m_prefix(prefix), m_havePronoun(havePronoun)
  {
  }

  FrenchMode::~FrenchMode()
  {
  }

  Mode*
  FrenchMode::clone() const
  {
    return new FrenchMode(*this);
  }

  bool
  FrenchMode::isLess(const Mode& val) const
  {
    bool res = false;
    try
      {
        const FrenchMode& mode = dynamic_cast<const FrenchMode&>(val);
        res= m_name < mode.getName();
      }
    catch (...)
      {
        /// The given mode is not a french mode, thus not comparable.
      }
    return res;
  }

}
