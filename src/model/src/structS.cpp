// structS.cpp

#include "../headers/structS.hpp"

StructS::StructS() {
}

const std::array< std::array< char, 5 >, 5 > &StructS::displayStruct() const override {
	if ( getPosition() == 1 )
		return frstPos();
	else if ( getPosition() == 2 )
		return scndPos(); 
	else if ( getPosition() == 3 )
		return thrdPos();
	else return frthPos();
}

const std::array< std::array< char, 5 >, 5 > &StructS::frstPos() const override {
	std::array< std::array< char, 5 >, 5 > Struct::element = { { { 0, 1, 1, 0, 0 },
     								     { 1, 1, 0, 0, 0 },
   								     { 0, 0, 0, 0, 0 },
      								     { 0, 0, 0, 0, 0 },
     								     { 0, 0, 0, 0, 0 },
    								   } };
}

const std::array< std::array< char, 5 >, 5 > &StructS::scndPos() const override {
	std::array< std::array< char, 5 >, 5 > Struct::element = { { { 1, 0, 0, 0, 0 },
      								     { 1, 1, 0, 0, 0 },
      								     { 0, 1, 0, 0, 0 },
      								     { 0, 0, 0, 0, 0 },
      								     { 0, 0, 0, 0, 0 },
    								   } };
}

const std::array< std::array< char, 5 >, 5 > &StructS::thrdPos() const override {
	std::array< std::array< char, 5 >, 5 > Struct::element = { { { 0, 1, 1, 0, 0 },
      								     { 1, 1, 0, 0, 0 },
      								     { 0, 0, 0, 0, 0 },
      								     { 0, 0, 0, 0, 0 },
    								     { 0, 0, 0, 0, 0 },
       								     { 0, 0, 0, 0, 0 },
     								   } };
}

const std::array< std::array< char, 5 >, 5 > &StructS::frthPos() const override {
	std::array< std::array< char, 5 >, 5 > Struct::element = { { { 1, 0, 0, 0, 0 },
      								     { 1, 1, 0, 0, 0 },
      								     { 0, 1, 0, 0, 0 },
      								     { 0, 0, 0, 0, 0 },
      								     { 0, 0, 0, 0, 0 },
     								   } };
}

StructS::~StructS() {
}
