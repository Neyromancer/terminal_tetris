// structS.hpp
#ifndef _STRUCT_S_HPP_
#define _STRUCT_S_HPP_

#include "struct.hpp"

class StructS: public Struct {
	public:
		StructS( size_t = 1, size_t = 0, size_t = 0 );
		~StructS() {}

		// return array of 0 and 1's which are 
		// represent elements
//		virtual void setWidth() override;
//		virtual void setHeight() override;
		virtual void setPos() override;

		virtual const std::array< std::array< size_t, 5 >, 5 > &getPos() const override;

		virtual void setFrstPos() override;
		virtual void setScndPos() override;
		virtual void setThrdPos() override;
		virtual void setFrthPos() override;

};

#endif
