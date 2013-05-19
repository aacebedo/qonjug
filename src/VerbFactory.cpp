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

///*
// * VerbFactory.cpp
// *
// *  Created on: 12 mai 2013
// *      Author: aacebedo
// */
//
//#include "VerbFactory.h"
//#include "VerbExceptionStorage.h"
//
//namespace qonjug
//{
//
//  std::string VerbFactory::ER_TERM("er");
//  std::string VerbFactory::ELER_TERM("eler");
//  std::string VerbFactory::CER_TERM("cer");
//  std::string VerbFactory::GER_TERM("ger");
//  std::string VerbFactory::AYER_TERM("ayer");
//  std::string VerbFactory::OYER_TERM("oyer");
//  std::string VerbFactory::UYER_TERM("uyer");
//
//  std::string VerbFactory::IR_TERM("ir");
//
//  VerbFactory::VerbFactory()
//  {
//  }
//
//  VerbFactory::~VerbFactory()
//  {
//  }
//
//  Verb*
//  VerbFactory::getVerb(const std::string& verbStr) throw (std::invalid_argument)
//  {
//    Group grp = getGroup(verbStr);
//    Verb* v = 0;
//    switch (grp)
//      {
//    case FIRST:
//      {
//        std::string radical4letters(verbStr.substr(verbStr.length() - 4));
//        std::string radical3letters(verbStr.substr(verbStr.length() - 3));
//        if (radical4letters == ELER_TERM || radical4letters == AYER_TERM
//            || radical4letters == OYER_TERM || radical4letters == UYER_TERM)
//          {
//            v = new Verb(
//                verbStr.substr(0, verbStr.length() - radical4letters.size()),
//                radical4letters, grp);
//          }
//        else if (radical3letters == CER_TERM || radical3letters == GER_TERM)
//          {
//            v = new Verb(
//                verbStr.substr(0, verbStr.length() - radical3letters.size()),
//                radical3letters, grp);
//          }
//        else
//          {
//            v = new Verb(verbStr.substr(0, verbStr.length() - ER_TERM.size()),
//                ER_TERM, grp);
//          }
//      }
//      break;
//    case SECOND:
//      v = new Verb(verbStr.substr(0, verbStr.length() - IR_TERM.size()),
//          IR_TERM, grp);
//      break;
//    case THIRD:
//      v = new Verb(verbStr, "", grp);
//      break;
//    default:
//      throw std::invalid_argument("Invalid group");
//      }
//    return v;
//  }
//
//  Group
//  VerbFactory::getGroup(const std::string& verbStr) const
//  {
//    Group res = GROUP_NB;
//    std::string radical = verbStr.substr(verbStr.length() - 2);
//    if (radical == ER_TERM)
//      {
//        res =
//            (VerbExceptionStorage::getExceptions(FIRST).count(verbStr) == 0) ?
//                FIRST : THIRD;
//      }
//    else if (radical == IR_TERM)
//      {
//        res =
//            (VerbExceptionStorage::getExceptions(SECOND).count(verbStr) == 0) ?
//                SECOND : THIRD;
//      }
//    else
//      {
//        res = THIRD;
//      }
//    return res;
//  }
//
//} /* namespace qonjug */
