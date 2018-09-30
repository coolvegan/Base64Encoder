//
// Created by marco on 30.09.18.
//

#include "ModuleTest.h"

#define BOOST_TEST_MODULE const_string test
#include <boost/test/unit_test.hpp>
#include "../Base64Encode.h"

BOOST_AUTO_TEST_CASE( Check_The_Translation_Of_test )
{
  std::string s = "test";
  Base64Encode encode(s);
  BOOST_CHECK_EQUAL("dGVzdA==", encode.converted());
}

BOOST_AUTO_TEST_CASE( Check_The_Translation_Of_Typesystem_Lisu )
{
  std::string s = "ꓒꓓꓔꓕꓱꓹꓺꓻꓼꓽ꓾꓿";
  Base64Encode encode(s);
  BOOST_CHECK_EQUAL("6pOS6pOT6pOU6pOV6pOx6pO56pO66pO76pO86pO96pO+6pO/", encode.converted());
}

BOOST_AUTO_TEST_CASE( Check_The_Translation_Of_Different_Typesystems )
{
  std::string s = "ꢀꢁꢂꢃꢄදජඓපබ්᮸᮷ᮩெோஸௐⵚⵐⵄⵡ";
  Base64Encode encode(s);
  BOOST_CHECK_EQUAL("6qKA6qKB6qKC6qKD6qKE4Lav4Lai4LaT4La04La24LeK4a644a634a6p4K+G4K+L4K644K+Q4rWa4rWQ4rWE4rWh", encode.converted());
}



