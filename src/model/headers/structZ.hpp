// structT.hpp
#ifndef _STRUCT_Z_HPP_
#define _STRUCT_Z_HPP_

#include "struct.hpp"

class StructZ: public Struct {
	public:
		StructZ();
		~StructZ();

		// return array of 0 and 1's which are 
		// represent elements
		virtual const std::array< std::array< char, 5 >, 5 > &displayStruct() const override;
		const std::array< std::array< char, 5 >, 5 > &frstPos() const override;
		virtual const std::array< std::array< char, 5 >, 5 > &scndPos() const override;
		virtual const std::array< std::array< char, 5 >, 5 > &thrdPos() const override;
		virtual const std::array< std::array< char, 5 >, 5 > &frthPos() const override;

};

#endif
