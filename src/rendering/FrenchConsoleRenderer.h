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

}
#endif
