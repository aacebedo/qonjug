/*
 * FrenchConsoleRenderer.h
 *
 *  Created on: 19 mai 2013
 *      Author: aacebedo
 */

#ifndef FRENCHCONSOLERENDERER_H_
#define FRENCHCONSOLERENDERER_H_

#include "ConsoleRenderer.h"

namespace qonjug
{

  class FrenchConsoleRenderer : public qonjug::ConsoleRenderer
  {
  public:
    FrenchConsoleRenderer();
    virtual
    ~FrenchConsoleRenderer();

    virtual void
           render(const Conjugation& c);
  };

} /* namespace qonjug */
#endif /* FRENCHCONSOLERENDERER_H_ */
