// structPoint.hpp
#ifndef _STRUCT_POINT_HPP_
#define _STRUCT_POINT_HPP_

#include "struct.hpp"

class StructPoint: public Struct {
	public:
		StructPoint();
		~StructPoint();

		// return array of 0 and 1's which are 
		// represent elements
		virtual const std::arrray< std::array< char >, 5 >, 5 > &displayStruct() const override;
		const std::arrray< std::array< char >, 5 >, 5 > &frstPos() const override;
		virtual const std::arrray< std::array< char >, 5 >, 5 > &scndPos() const override;
		virtual const std::arrray< std::array< char >, 5 >, 5 > &thrdPos() const override;
		virtual const std::arrray< std::array< char >, 5 >, 5 > &frthPos() const override;

};

