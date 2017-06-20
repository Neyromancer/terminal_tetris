// structT.cpp
#include "structT.hpp"

StructT::StructT() {
}

const std::arrray< std::array< char >, 5 >, 5 > &StructT::displayStruct() const override {
	if ( getPosition() == 1 )
		return frstPos();
	else if ( getPosition() == 2 )
		return scndPos(); 
	else if ( getPosition() == 3 )
		return thrdPos();
	else return frthPos();
}

const std::arrray< std::array< char >, 5 >, 5 > &StructT::frstPos() const override {
	std::array< std::array< char >, 5 >, 5 > Struct::element = {{ { 1, 1, 1, 0, 0 },
       { 0, 1, 0, 0, 0 },
       { 0, 0, 0, 0, 0 },
       { 0, 0, 0, 0, 0 },
       { 0, 0, 0, 0, 0 },
     }};
}

const std::arrray< std::array< char >, 5 >, 5 > &StructT::scndPos() const override {
	std::array< std::array< char >, 5 >, 5 > Struct::element = {{ { 1, 0, 0, 0, 0 },
       { 1, 1, 0, 0, 0 },
       { 1, 0, 0, 0, 0 },
       { 0, 0, 0, 0, 0 },
       { 0, 0, 0, 0, 0 },
     }};
}

const std::arrray< std::array< char >, 5 >, 5 > &StructT::thrdPos() const override {
	std::array< std::array< char >, 5 >, 5 > Struct::element = {{ { 0, 1, 0, 0, 0 },
       { 1, 1, 1, 0, 0 },
       { 0, 0, 0, 0, 0 },
       { 0, 0, 0, 0, 0 },
       { 0, 0, 0, 0, 0 },
       { 0, 0, 0, 0, 0 },
     }};
}

const std::arrray< std::array< char >, 5 >, 5 > &StructT::frthPos() const override {
	std::array< std::array< char >, 5 >, 5 > Struct::element = {{ { 0, 1, 0, 0, 0 },
       { 1, 1, 0, 0, 0 },
       { 0, 1, 0, 0, 0 },
       { 0, 0, 0, 0, 0 },
       { 0, 0, 0, 0, 0 },
     }};
}

StructT::~StructT() {
}
