/*
 * Renderable.h
 *
 *  Created on: 15 mai 2013
 *      Author: aacebedo
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

#endif /* CLONEABLE_H_ */
