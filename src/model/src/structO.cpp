// structO.cpp

#include "../headers/structO.hpp"

StructO::StructO() {
}

const std::array< std::array< char, 5 >, 5 > &StructO::displayStruct() const override {
	if ( getPosition() == 1 )
		return frstPos();
	else if ( getPosition() == 2 )
		return scndPos(); 
	else if ( getPosition() == 3 )
		return thrdPos();
	else return frthPos();
}

const std::array< std::array< char, 5 >, 5 > &StructO::frstPos() const override {
	std::array< std::array< char, 5 >, 5 > Struct::element = { { { 1, 1, 0, 0, 0 },
      								     { 1, 1, 0, 0, 0 },
      								     { 0, 0, 0, 0, 0 },
      								     { 0, 0, 0, 0, 0 },
     								     { 0, 0, 0, 0, 0 },
  								   } };
}

const std::array< std::array< char, 5 >, 5 > &StructO::scndPos() const override {
	std::array< std::array< char, 5 >, 5 > Struct::element = { { { 1, 1, 0, 0, 0 },
      								     { 1, 1, 0, 0, 0 },
     								     { 0, 0, 0, 0, 0 },
      								     { 0, 0, 0, 0, 0 },
     								     { 0, 0, 0, 0, 0 },
     								    } };
}

const std::array< std::array< char, 5 >, 5 > &StructO::thrdPos() const override {
	std::array< std::array< char, 5 >, 5 > Struct::element = { { { 1, 1, 0, 0, 0 },
    								     { 1, 1, 0, 0, 0 },
    								     { 0, 0, 0, 0, 0 },
     								     { 0, 0, 0, 0, 0 },
      								     { 0, 0, 0, 0, 0 },
     								     { 0, 0, 0, 0, 0 },
   								   } };
}

const std::array< std::array< char, 5 >, 5 > &StructO::frthPos() const override {
	std::array< std::array< char, 5 >, 5 > Struct::element = { { { 1, 1, 0, 0, 0 },
      								     { 1, 1, 0, 0, 0 },
       								     { 0, 0, 0, 0, 0 },
     								     { 0, 0, 0, 0, 0 },
    								     { 0, 0, 0, 0, 0 },
     								   } };
}

StructO::~StructO() {
}
