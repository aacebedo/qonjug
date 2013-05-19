/*
 * ConsoleRenderer.cpp
 *
 *  Created on: 18 mai 2013
 *      Author: aacebedo
 */

#include <stdlib.h>
#include <iostream>

#include "rendering/ConsoleRenderer.h"

namespace qonjug
{

  ConsoleRenderer::ConsoleRenderer()
  {
    // TODO Auto-generated constructor stub

  }

  ConsoleRenderer::~ConsoleRenderer()
  {
    // TODO Auto-generated destructor stub
  }

  void
  ConsoleRenderer::render(const Conjugation& c)
  {
    std::cout << c.getMode().getName() << " " << c.getTense().getName() << ":"
        << std::endl;

    for (Conjugation::Terms::const_iterator it = c.getTerms().begin();
        it != c.getTerms().end(); ++it)
      {

     //   if(((it->first.getPronoun()=="je" && std::find(voyels,voyels+(sizeof(voyels)/sizeof(char)),c.getTerms()[0]))))

        std::cout << it->first.getPronoun() << " " << it->second << std::endl;
      }
    std::cout << std::endl;
    std::cout << std::endl;
    std::cout << std::endl;

  }

} /* namespace konjugueur */
