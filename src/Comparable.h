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

#ifndef QONJUG_COMPARABLE_H_
#define QONJUG_COMPARABLE_H_

namespace qonjug
{
  template<typename T>
    /**
     * Interface for Comparable objects.
     * Implementing this interface means that object can be compared
     */
    class Comparable
    {
    public:

      /**
       * Default destructor.
       */
      virtual
      ~Comparable() = 0;

      /**
       * Test for less object.
       * @param val the value to compare to.
       * @return a boolean if the current object is less than the given value.
       */
      virtual bool
      isLess(const T& val) const = 0;
    };
}

namespace qonjug
{
  template<typename T>
    Comparable<T>::~Comparable()
    {
    }
}

#endif
