/*
 * Verb.h
 *
 *  Created on: 12 mai 2013
 *      Author: aacebedo
 */

#ifndef VERB_H_
#define VERB_H_

#include <string>

#include "Clonable.h"

namespace qonjug
{

  class Verb : public Clonable<Verb>
  {
  public:

    virtual
    ~Verb() = 0;

    virtual std::string
    toString() const = 0;

  };

} /* namespace qonjug */


#endif /* VERB_H_ */
