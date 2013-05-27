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

#ifndef QONJUG_TENSE_H_
#define QONJUG_TENSE_H_

#include <string>

#include "Clonable.h"
#include "Comparable.h"

namespace qonjug
{

  /**
   * Interface representing the tense concept.
   */
  class Tense : public Clonable<Tense>, public Comparable<Tense>
  {
  public:
    /**
     * Destructor
     */
    virtual
    ~Tense() = 0;

    /**
     * Get the tense's name.
     * @return the tense's name.
     */
    virtual const std::string&
    getName() const = 0;

  };
}

#endif
