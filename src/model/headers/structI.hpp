// structI.hpp
#ifndef _STRUCT_I_HPP_
#define _STRUCT_I_HPP_

#include "struct.hpp"

class StructI: public Struct {
	public:
		StructI( size_t pos = 1, size_t x = 0, size_t y = 0 );
		~StructI(){}

		// return array of 0 and 1's which are 
		// represent elements
		virtual std::array< std::array< size_t, 5 >, 5 > &displayStruct() override;
		virtual std::array< std::array< size_t, 5 >, 5 > &frstPos() override;
		virtual std::array< std::array< size_t, 5 >, 5 > &scndPos() override;
		virtual std::array< std::array< size_t, 5 >, 5 > &thrdPos() override;
		virtual std::array< std::array< size_t, 5 >, 5 > &frthPos() override;

};

#endif
