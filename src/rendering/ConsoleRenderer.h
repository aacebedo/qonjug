/*
 * ConsoleRenderer.h
 *
 *  Created on: 18 mai 2013
 *      Author: aacebedo
 */

#ifndef CONSOLERENDERER_H_
#define CONSOLERENDERER_H_

#include "rendering/Renderer.h"

namespace qonjug
{

  class ConsoleRenderer : public Renderer
  {
  public:
    ConsoleRenderer();
    virtual
    ~ConsoleRenderer();

    virtual void
       render(const Conjugation& c);

  };

} /* namespace konjugueur */
#endif /* CONSOLERENDERER_H_ */
