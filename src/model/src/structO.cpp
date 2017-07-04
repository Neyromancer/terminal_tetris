// structO.cpp

#include "../headers/structO.hpp"

StructO::StructO( size_t pos, size_t x, size_t y )
	: Struct( pos, x, y ) {
}

std::array< std::array< size_t, 5 >, 5 > &StructO::displayStruct() {
	switch( getPosition() ) {
		case 1: return frstPos();
		case 2: return scndPos();
		case 3: return thrdPos();
	}
/*
	if ( getPosition() == 1 )
		return frstPos();
	else if ( getPosition() == 2 )
		return scndPos(); 
	else if ( getPosition() == 3 )
		return thrdPos();
	else 
*/
	return frthPos();
}

std::array< std::array< size_t, 5 >, 5 > &StructO::frstPos() {
	return Struct::element = { { { 1, 1, 0, 0, 0 },
      								     				    { 1, 1, 0, 0, 0 },
      								     				    { 0, 0, 0, 0, 0 },
      								     				    { 0, 0, 0, 0, 0 },
     								     				    { 0, 0, 0, 0, 0 },
  								   				  } };
}

std::array< std::array< size_t, 5 >, 5 > &StructO::scndPos() {
	return Struct::element = { { { 1, 1, 0, 0, 0 },
      								     				    { 1, 1, 0, 0, 0 },
     								     				    { 0, 0, 0, 0, 0 },
      								     				    { 0, 0, 0, 0, 0 },
     								     				    { 0, 0, 0, 0, 0 },
     								    				  } };
}

std::array< std::array< size_t, 5 >, 5 > &StructO::thrdPos() {
	return Struct::element = { { { 1, 1, 0, 0, 0 },
    								     				    { 1, 1, 0, 0, 0 },
    								     				    { 0, 0, 0, 0, 0 },
     								     				    { 0, 0, 0, 0, 0 },
      								    				    { 0, 0, 0, 0, 0 },
   								   				  } };
}

std::array< std::array< size_t, 5 >, 5 > &StructO::frthPos() {
	return Struct::element = { { { 1, 1, 0, 0, 0 },
      								     				    { 1, 1, 0, 0, 0 },
       								    				    { 0, 0, 0, 0, 0 },
     								     				    { 0, 0, 0, 0, 0 },
    								     				    { 0, 0, 0, 0, 0 },
     								   				  } };
}
/*
StructO::~StructO() {
}
*/
