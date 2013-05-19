/*
 * FrenchConsoleRenderer.cpp
 *
 *  Created on: 19 mai 2013
 *      Author: aacebedo
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
        std::cout << mode.getPrefix()
            << ((mode.havePronoun()) ?
                (it->first.getPronoun() == "je" && std::find(voyels,voyels+(sizeof(voyels)/sizeof(char)),it->second[0])!=voyels+(sizeof(voyels)/sizeof(char)))?
                    "j'":it->first.getPronoun() + " " : " ")
            << it->second << std::endl;

      }
    std::cout << std::endl;

  }

} /* namespace qonjug */
