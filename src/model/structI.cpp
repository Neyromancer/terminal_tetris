// structI.cpp
#include "structI.hpp"

StructI::StructI() {
}

const std::arrray< std::array< char >, 5 >, 5 > &StructI::displayStruct() const override {
	if ( getPosition() == 1 )
		return frstPos();
	else if ( getPosition() == 2 )
		return scndPos(); 
	else if ( getPosition() == 3 )
		return thrdPos();
	else return frthPos();
}

const std::arrray< std::array< char >, 5 >, 5 > &StructI::frstPos() const override {
	std::array< std::array< char >, 5 >, 5 > Struct::element = {{ { 0, 0, 0, 0, 0 },
       { 0, 0, 0, 0, 0 },
       { 0, 0, 0, 0, 0 },
       { 0, 0, 0, 0, 0 },
       { 1, 1, 1, 1, 0 },
     }};
}

const std::arrray< std::array< char >, 5 >, 5 > &StructI::scndPos() const override {
	std::array< std::array< char >, 5 >, 5 > Struct::element = {{ { 1, 0, 0, 0, 0 },
       { 1, 0, 0, 0, 0 },
       { 1, 0, 0, 0, 0 },
       { 1, 0, 0, 0, 0 },
       { 0, 0, 0, 0, 0 },
     }};
}

const std::arrray< std::array< char >, 5 >, 5 > &StructI::thrdPos() const override {
	std::array< std::array< char >, 5 >, 5 > Struct::element = {{ { 0, 0, 0, 0, 0 },
       { 0, 0, 0, 0, 0 },
       { 0, 0, 0, 0, 0 },
       { 0, 0, 0, 0, 0 },
       { 0, 0, 0, 0, 0 },
       { 1, 1, 1, 1, 0 },
     }};
}

const std::arrray< std::array< char >, 5 >, 5 > &StructI::frthPos() const override {
	std::array< std::array< char >, 5 >, 5 > Struct::element = {{ { 1, 0, 0, 0, 0 },
       { 1, 0, 0, 0, 0 },
       { 1, 0, 0, 0, 0 },
       { 1, 0, 0, 0, 0 },
       { 0, 0, 0, 0, 0 },
     }};
}

StructI::~StructI() {
}
