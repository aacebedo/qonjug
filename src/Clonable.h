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

#ifndef CLONABLE_H_
#define CLONABLE_H_

namespace qonjug
{

  template<typename T>
    class Clonable
    {
    public:

      virtual
      ~Clonable() = 0;

      virtual T*
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
