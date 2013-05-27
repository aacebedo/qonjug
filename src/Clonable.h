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

#ifndef QONJUG_CLONABLE_H_
#define QONJUG_CLONABLE_H_

#include <boost/shared_ptr.hpp>

namespace qonjug
{
  template<typename T>
    /**
     * Interface for clonable objects.
     * Implementing this interface means that object is able to to clone itself.
     */
    class Clonable
    {
    public:

      /**
       * Default destructor.
       */
      virtual
      ~Clonable() = 0;

      /**
       * Creates and returns a clone of the object.
       */
      virtual boost::shared_ptr<T>
      clone() const = 0;
    };
}

namespace qonjug
{
  template<typename T>
    Clonable<T>::~Clonable()
    {
    }
}

#endif
