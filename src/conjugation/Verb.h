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
#ifndef QONJUG_VERB_H_
#define QONJUG_VERB_H_

#include <string>

#include "Clonable.h"

namespace qonjug
{

  /**
   * Interface representing the verb concept.
   */
  class Verb : public Clonable<Verb>
  {
  public:

    /**
     * Destructor
     */
    virtual
    ~Verb() = 0;

    /**
     * Get a string representation of the verb.
     * @return the representing string.
     */
    virtual std::string
    toString() const = 0;

  };

}

#endif
