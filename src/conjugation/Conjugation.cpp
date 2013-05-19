/*
 * Conjugation.cpp
 *
 *  Created on: 14 mai 2013
 *      Author: aacebedo
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

} /* namespace qonjug */
