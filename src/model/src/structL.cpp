// structL.cpp

#include "../headers/structL.hpp"

StructL::StructL( size_t pos, size_t x, size_t y )
	: Struct( pos, x, y ) {
}

std::array< std::array< size_t, 5 >, 5 > &StructL::displayStruct() {
	switch( getPosition() ) {
		case 1: return frstPos();
		case 2: return scndPos();
		case 3: return thrdPos();
	}

	return frthPos();

/*
	if ( getPosition() == 1 )
		return frstPos();
	else if ( getPosition() == 2 )
		return scndPos(); 
	else if ( getPosition() == 3 )
		return thrdPos();
	else return frthPos();
*/
}

std::array< std::array< size_t, 5 >, 5 > &StructL::frstPos() {
	return Struct::element = { { { 1, 1, 1, 0, 0 },
      								     				    { 1, 0, 0, 0, 0 },
      								     				    { 0, 0, 0, 0, 0 },
     								     				    { 0, 0, 0, 0, 0 },
    								     				    { 0, 0, 0, 0, 0 },
    								   				  } };
}

std::array< std::array< size_t, 5 >, 5 > &StructL::scndPos() {
	return Struct::element = { { { 1, 0, 0, 0, 0 },
     								     				    { 1, 0, 0, 0, 0 },
      								     				    { 1, 1, 0, 0, 0 },
      								     				    { 0, 0, 0, 0, 0 },
      								     				    { 0, 0, 0, 0, 0 },
    							 	  				  } };
}

std::array< std::array< size_t, 5 >, 5 > &StructL::thrdPos() {
	return Struct::element = { { { 0, 0, 1, 0, 0 },
     								     				    { 1, 1, 1, 0, 0 },
      								     				    { 0, 0, 0, 0, 0 },
     								     				    { 0, 0, 0, 0, 0 },
     								     				    { 0, 0, 0, 0, 0 },
     								   				 } };
}

std::array< std::array< size_t, 5 >, 5 > &StructL::frthPos() {
	return Struct::element = { { { 0, 1, 1, 0, 0 },
      								     				    { 0, 0, 1, 0, 0 },
       								     				    { 0, 0, 1, 0, 0 },
       								     				    { 0, 0, 0, 0, 0 },
      								     				    { 0, 0, 0, 0, 0 },
     								   } };
}
/*
StructL::~StructL() {
}
*/
