/*
 * Clonable.h
 *
 *  Created on: 15 mai 2013
 *      Author: aacebedo
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

#endif /* CLONEABLE_H_ */
