// structZ.cpp

#include "../headers/structZ.hpp"

StructZ::StructZ() {
}

const std::array< std::array< char, 5 >, 5 > &StructZ::displayStruct() const override {
	if ( getPosition() == 1 )
		return frstPos();
	else if ( getPosition() == 2 )
		return scndPos(); 
	else if ( getPosition() == 3 )
		return thrdPos();
	else return frthPos();
}

const std::array< std::array< char, 5 >, 5 > &StructZ::frstPos() const override {
	std::array< std::array< char, 5 >, 5 > Struct::element = { { { 1, 1, 0, 0, 0 },
      								     { 0, 1, 1, 0, 0 },
      								     { 0, 0, 0, 0, 0 },
      								     { 0, 0, 0, 0, 0 },
    								     { 0, 0, 0, 0, 0 },
    								   } };
}

const std::array< std::array< char, 5 >, 5 > &StructZ::scndPos() const override {
	std::array< std::array< char, 5 >, 5 > Struct::element = { { { 0, 1, 0, 0, 0 },
      								     { 1, 1, 0, 0, 0 },
    								     { 1, 0, 0, 0, 0 },
       								     { 0, 0, 0, 0, 0 },
   								     { 0, 0, 0, 0, 0 },
     								   } };
}

const std::array< std::array< char, 5 >, 5 > &StructZ::thrdPos() const override {
	std::array< std::array< char, 5 >, 5 > Struct::element = { { { 1, 1, 0, 0, 0 },
   								     { 0, 1, 1, 0, 0 },
  								     { 0, 0, 0, 0, 0 },
      								     { 0, 0, 0, 0, 0 },
      								     { 0, 0, 0, 0, 0 },
    								   } };
}

const std::array< std::array< char, 5 >, 5 > &StructZ::frthPos() const override {
	std::array< std::array< char, 5 >, 5 > Struct::element = { { { 0, 1, 0, 0, 0 },
     								     { 1, 1, 0, 0, 0 },
       								     { 1, 0, 0, 0, 0 },
       								     { 0, 0, 0, 0, 0 },
       								     { 0, 0, 0, 0, 0 },
     								   } };
}

StructZ::~StructZ() {
}
