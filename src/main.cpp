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

#include "conjugation/Verb.h"
#include "conjugation/Conjugation.h"
#include "rendering/FrenchConsoleRenderer.h"
#include "backend/french/FrenchSQLiteBackend.h"

#include <log4cxx/logger.h>
#include <iostream>
#include <iterator>
#include <algorithm>
#include "KompexSQLiteException.h"
#include <tclap/CmdLine.h>
#include <boost/scoped_ptr.hpp>

#include "log4cxx/logger.h"
#include "log4cxx/basicconfigurator.h"
#include "log4cxx/helpers/exception.h"
using namespace qonjug;

int
main(int argc, char** argv)
{

  try
   {

   TCLAP::CmdLine cmd("Quonjug", ' ', "0.1");

   TCLAP::UnlabeledValueArg<std::string>  verbArg( "verb", "Verb to conjugate",true,"",
   "Verb to conjugate","string"  );
   cmd.add( verbArg );
   cmd.parse(argc, argv);

   // Get the value parsed by each arg.
   std::string name = verbArg.getValue();



   }
   catch (TCLAP::ArgException &e)  // catch any exceptions
   {
   std::cerr << "error: " << e.error() << " for arg " << e.argId()
   << std::endl;
   }

  boost::scoped_ptr<Renderer> pRenderer( new FrenchConsoleRenderer());
  FrenchSQLiteBackend b("share/conjugation_fr.db");
  boost::scoped_ptr<FrenchSQLiteBackend::VerbSearchResult> res(b.searchVerb("chanter"));
  const FrenchSQLiteBackend::Modes& m = b.getAvailableModes();
  const FrenchSQLiteBackend::Tenses& t = b.getAvailableTenses();
  boost::scoped_ptr<ConjugationBackend::Conjugations> c(b.conjugate(**res->begin()));


  for (ConjugationBackend::Conjugations::iterator itC = c->begin();
       itC != c->end(); ++itC)
    {
     (**itC).render(*pRenderer);

    }


//  log4cxx::BasicConfigurator::configure();
 //     log4cxx::LoggerPtr logger(log4cxx::Logger::getLogger("main"));
   //   LOG4CXX_DEBUG(logger, "Hello World");




return 0;

  //Conjugation* c;
  //for (FrenchSQLiteBackend::Modes::const_iterator itMode = m-begin();
   //   itMode != m.end(); ++itMode)
    //{
    //  std::cout << (*itMode).getName() << std::endl;
      /*for (FrenchSQLiteBackend::Tenses::const_iterator itTense = t.begin();
          itTense != t.end(); ++itTense)
        {
          //std::cout << it->toString() << std::endl;
          for (std::vector<boost::shared_ptr<Verb> >::iterator it =
              res->begin(); it != res->end(); ++it)
            {
              c = b.conjugate(**it, *itMode, *itTense);
              ConsoleRenderer r;
              c->render(pRenderer);
              for (Conjugation::Terms::const_iterator i =
                  c->getTerms().begin(); i != c->getTerms().end();
                  ++i)
                {
                  std::cout << (*i).second << std::endl;
                }

            }

        }*/
    //}

}
