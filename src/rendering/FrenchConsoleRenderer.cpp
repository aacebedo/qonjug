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

#include "conjugation/french/FrenchMode.h"
#include "conjugation/french/FrenchVerb.h"
#include "conjugation/french/FrenchTense.h"
#include "FrenchConsoleRenderer.h"
#include <iostream>
#include <sstream>
#include <algorithm>
namespace qonjug
{

  FrenchConsoleRenderer::FrenchConsoleRenderer()
  {
  }

  FrenchConsoleRenderer::~FrenchConsoleRenderer()
  {
  }

  void
  FrenchConsoleRenderer::render(const Conjugation& c)
  {
    const FrenchMode& mode = dynamic_cast<const FrenchMode&>(c.getMode());
    const FrenchTense& tense = dynamic_cast<const FrenchTense&>(c.getTense());



    std::cout << mode.getName() << " " << tense.getName() << ":" << std::endl;


    char voyels[]= {'a','e','i','o','u'};
    for (Conjugation::Terms::const_iterator it = c.getTerms().begin();
        it != c.getTerms().end(); ++it)
      {
        std::cout << mode.getPrefix() << " "
            << ((mode.havePronoun()) ?
                (it->first.getPronoun() == "je" && std::find(voyels,voyels+(sizeof(voyels)/sizeof(char)),it->second[0])!=voyels+(sizeof(voyels)/sizeof(char)))?
                    "j'":it->first.getPronoun() + " " : " ")
            << it->second << std::endl;

      }
    std::cout << std::endl;

  }

}
