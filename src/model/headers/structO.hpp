// structO.hpp
#ifndef _STRUCT_O_HPP_
#define _STRUCT_O_HPP_

#include "struct.hpp"

class StructO: public Struct {
	public:
		StructO();
		~StructO();

		// return array of 0 and 1's which are 
		// represent elements
		virtual const std::array< std::array< char, 5 >, 5 > &displayStruct() const override;
		const std::array< std::array< char, 5 >, 5 > &frstPos() const override;
		virtual const std::array< std::array< char, 5 >, 5 > &scndPos() const override;
		virtual const std::array< std::array< char, 5 >, 5 > &thrdPos() const override;
		virtual const std::array< std::array< char, 5 >, 5 > &frthPos() const override;

};

#endif
