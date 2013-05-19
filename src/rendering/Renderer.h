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

#endif
