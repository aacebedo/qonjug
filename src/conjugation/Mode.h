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

#ifndef QONJUG_MODE_H_
#define QONJUG_MODE_H_

#include <string>
#include "Clonable.h"
#include "Comparable.h"

namespace qonjug
{
  /**
   * Interface representing the Mode concept.
   */
  class Mode : public Clonable<Mode>, public Comparable<Mode>
  {
  public:

    /**
     * Destructor.
     */
    virtual
    ~Mode() = 0;

    /**
     * Get the mode's name.
     * @return a mode's name.
     */
    virtual const std::string&
    getName() const = 0;

  };
}

#endif
