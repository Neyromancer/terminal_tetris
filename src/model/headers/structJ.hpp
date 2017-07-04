// structJ.hpp
#ifndef _STRUCT_J_HPP_
#define _STRUCT_J_HPP_

#include "struct.hpp"

class StructJ: public Struct {
	public:
		StructJ( size_t = 1, size_t = 0, size_t = 0 );
		~StructJ() {}

		// return array of 0 and 1's which are 
		// represent elements
		virtual std::array< std::array< size_t, 5 >, 5 > &displayStruct() override;
		virtual std::array< std::array< size_t, 5 >, 5 > &frstPos() override;
		virtual std::array< std::array< size_t, 5 >, 5 > &scndPos() override;
		virtual std::array< std::array< size_t, 5 >, 5 > &thrdPos() override;
		virtual std::array< std::array< size_t, 5 >, 5 > &frthPos() override;

};

#endif
