/*
 * FrenchTense.h
 *
 *  Created on: 19 mai 2013
 *      Author: aacebedo
 */

#ifndef FRENCHTENSE_H_
#define FRENCHTENSE_H_

#include "conjugation/Tense.h"

namespace qonjug
{
  class FrenchTense : public Tense
  {
  public:
    FrenchTense(const std::string& name, FrenchTense const* auxTense);
    virtual
    ~FrenchTense();

    virtual Tense* clone() const;

    FrenchTense const* getAuxTense() const;

  private:
    bool m_haveAux;
    FrenchTense const* m_auxTense;
  };

}

namespace qonjug
{
  inline FrenchTense const* FrenchTense::getAuxTense() const
  {
    return m_auxTense;
  }
}
#endif /* FRENCHTENSE_H_ */
