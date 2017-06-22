// structJ.cpp

#include "../headers/structJ.hpp"

StructJ::StructJ() {
}

const std::array< std::array< char, 5 >, 5 > &StructJ::displayStruct() const override {
	if ( getPosition() == 1 )
		return frstPos();
	else if ( getPosition() == 2 )
		return scndPos(); 
	else if ( getPosition() == 3 )
		return thrdPos();
	else return frthPos();
}

const std::array< std::array< char, 5 >, 5 > &StructJ::frstPos() const override {
	std::array< std::array< char, 5 >, 5 > Struct::element = { { { 1, 1, 1, 0, 0 },
       								     { 0, 0, 1, 0, 0 },
      								     { 0, 0, 0, 0, 0 },
     								     { 0, 0, 0, 0, 0 },
      								     { 0, 0, 0, 0, 0 },
     								   } };
}

const std::array< std::array< char, 5 >, 5 > &StructJ::scndPos() const override {
	std::array< std::array< char, 5 >, 5 > Struct::element = { { { 1, 1, 0, 0, 0 },
   								     { 1, 0, 0, 0, 0 },
    								     { 1, 0, 0, 0, 0 },
     								     { 0, 0, 0, 0, 0 },
   								     { 0, 0, 0, 0, 0 },
     								   } };
}

const std::array< std::array< char, 5 >, 5 > &StructJ::thrdPos() const override {
	std::array< std::array< char, 5 >, 5 > Struct::element = { { { 1, 0, 0, 0, 0 },
      								     { 1, 1, 1, 0, 0 },
     								     { 0, 0, 0, 0, 0 },
     								     { 0, 0, 0, 0, 0 },
      								     { 0, 0, 0, 0, 0 },
      								     { 0, 0, 0, 0, 0 },
     								   } };
}

const std::array< std::array< char, 5 >, 5 > &StructJ::frthPos() const override {
	std::array< std::array< char, 5 >, 5 > Struct::element = { { { 0, 0, 1, 0, 0 },
     								     { 0, 0, 1, 0, 0 },
 								     { 0, 1, 1, 0, 0 },
      								     { 0, 0, 0, 0, 0 },
   								     { 0, 0, 0, 0, 0 },
    								   } };
}

StructJ::~StructJ() {
}
