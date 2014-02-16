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

#include "FrenchTense.h"

namespace qonjug
{

  FrenchTense::FrenchTense(const std::string& name,
      const FrenchTense* pAuxTense) :
      m_name(name)
  {
    m_pAuxTense = 0;
    if (pAuxTense != 0)
      {
        m_pAuxTense = dynamic_cast<FrenchTense*>(pAuxTense->clone());
      }
  }

  FrenchTense::FrenchTense(const FrenchTense& orig) :
      Tense(orig)
  {
    if (orig.m_pAuxTense != 0)
      {
        m_pAuxTense = new FrenchTense(*(orig.m_pAuxTense));
      }
    else
      {
        m_pAuxTense = orig.m_pAuxTense;
      }
  }

  FrenchTense::~FrenchTense()
  {
    delete m_pAuxTense;
  }

  Tense*
  FrenchTense::clone() const
  {
    return new FrenchTense(*this);
  }

  bool
  FrenchTense::isLess(const Tense& val) const
  {
    bool res = false;
    try
      {
        const FrenchTense& tense = dynamic_cast<const FrenchTense&>(val);
        res = m_name < tense.getName();
      }
    catch (...)
      {
        /// The given mode is not a french mode, thus not comparable.
      }
    return res;
  }
}
