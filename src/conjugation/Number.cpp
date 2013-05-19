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

#include "conjugation/Number.h"

namespace qonjug
{

  Number
   fromIntToNumber(const int& val) throw (std::invalid_argument)
   {
     Number res = NUMBER_NB;
     switch (val)
       {
     case 1:
       res = SINGLE;
       break;
     case 2:
       res = PLURAL;
       break;
     default:
       throw std::invalid_argument("");
       }
     return res;
   }

}
