// structL.cpp
#include "structL.hpp"

StructL::StructL() {
}

const std::arrray< std::array< char, 5 >, 5 > &StructL::displayStruct() const override {
	if ( getPosition() == 1 )
		return frstPos();
	else if ( getPosition() == 2 )
		return scndPos(); 
	else if ( getPosition() == 3 )
		return thrdPos();
	else return frthPos();
}

const std::array< std::array< char, 5 >, 5 > &StructL::frstPos() const override {
	std::array< std::array< char, 5 >, 5 > Struct::element = { { { 1, 1, 1, 0, 0 },
      								     { 1, 0, 0, 0, 0 },
      								     { 0, 0, 0, 0, 0 },
     								     { 0, 0, 0, 0, 0 },
    								     { 0, 0, 0, 0, 0 },
    								   } };
}

const std::array< std::array< char, 5 >, 5 > &StructL::scndPos() const override {
	std::array< std::array< char, 5 >, 5 > Struct::element = { { { 1, 0, 0, 0, 0 },
     								     { 1, 0, 0, 0, 0 },
      								     { 1, 1, 0, 0, 0 },
      								     { 0, 0, 0, 0, 0 },
      								     { 0, 0, 0, 0, 0 },
    							 	   } };
}

const std::array< std::array< char, 5 >, 5 > &StructL::thrdPos() const override {
	std::array< std::array< char, 5 >, 5 > Struct::element = { { { 0, 0, 1, 0, 0 },
     								     { 1, 1, 1, 0, 0 },
      								     { 0, 0, 0, 0, 0 },
     								     { 0, 0, 0, 0, 0 },
     								     { 0, 0, 0, 0, 0 },
    								     { 0, 0, 0, 0, 0 },
     								   } };
}

const std::array< std::array< char, 5 >, 5 > &StructL::frthPos() const override {
	std::array< std::array< char, 5 >, 5 > Struct::element = { { { 0, 1, 1, 0, 0 },
      								     { 0, 0, 1, 0, 0 },
       								     { 0, 0, 1, 0, 0 },
       								     { 0, 0, 0, 0, 0 },
      								     { 0, 0, 0, 0, 0 },
     								   } };
}

StructL::~StructL() {
}
