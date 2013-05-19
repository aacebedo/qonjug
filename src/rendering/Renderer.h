/*
 * Renderer.h
 *
 *  Created on: 15 mai 2013
 *      Author: aacebedo
 */

#ifndef RENDERER_H_
#define RENDERER_H_

#include "conjugation/Conjugation.h"

namespace qonjug
{

  class Renderer
  {
  public:

    virtual
    ~Renderer() = 0;

    virtual void
    render(const Conjugation& c) = 0;
  };
}

namespace qonjug
{

  inline Renderer::~Renderer()
  {
  }
}

#endif /* CLONEABLE_H_ */
