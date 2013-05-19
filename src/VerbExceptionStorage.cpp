///*
// * VerbExceptionStorage.cpp
// *
// *  Created on: 12 mai 2013
// *      Author: aacebedo
// */
//
//#include "VerbExceptionStorage.h"
//#include <pugixml.hpp>
//#include <iostream>
//#include <sstream>
//#include <algorithm>
//using namespace std;
//
//namespace qonjug
//{
//
//  VerbExceptionStorage::VerbExceptionStorage()
//  {
//  }
//
//  VerbExceptionStorage::~VerbExceptionStorage()
//  {
//  }
//
//  std::set<std::string>
//  VerbExceptionStorage::getExceptions(Group group) throw (std::invalid_argument)
//  {
//    std::set<std::string> res;
//
//    pugi::xml_document doc;
//    doc.load_file("./exceptions.xml");
//
//    std::ostringstream query;
//    query << "/qonjug/group[@id='" << group << "']//verb";
//
//    pugi::xpath_node_set verbs = doc.select_nodes(query.str().c_str());
//    for (pugi::xpath_node_set::const_iterator it = verbs.begin();
//        it != verbs.end(); ++it)
//      {
//        res.insert(it->node().attribute("id").as_string());
//      }
//    return res;
//  }
//
//
//} /* namespace qonjug */
