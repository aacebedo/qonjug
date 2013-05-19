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

#ifndef RENDERABLE_H_
#define RENDERABLE_H_

namespace qonjug
{
  class Renderer;
}

namespace qonjug
{

  class Renderable
  {
  public:

    virtual
    ~Renderable() = 0;

    virtual void
    render(Renderer * pRenderer) const = 0;
  };
}

namespace qonjug
{

  inline Renderable::~Renderable()
  {
  }
}

#endif
