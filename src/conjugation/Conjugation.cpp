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

#include "conjugation/Conjugation.h"
#include "conjugation/Verb.h"
#include "conjugation/Mode.h"
#include "conjugation/Tense.h"

#include "rendering/Renderer.h"

namespace qonjug
{

  Conjugation::Conjugation(const Verb& verb, const Mode& mode,
      const Tense& tense, Terms terms) :
      m_pMode(mode), m_pTense(tense), m_terms(terms)
  {
    m_pVerb = verb.clone();
  }

  Conjugation::~Conjugation()
  {
  }

  void
  Conjugation::render(Renderer * pRenderer) const
  {
    pRenderer->render(*this);
  }

}
