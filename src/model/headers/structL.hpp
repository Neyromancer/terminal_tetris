// structL.hpp
#ifndef _STRUCT_L_HPP_
#define _STRUCT_L_HPP_

#include "struct.hpp"

class StructL: public Struct {
	public:
		StructL(size_t = 1, size_t = 0, size_t = 0);
    StructL(const StructL &) = default;
    StructL &operator=(const StructL &) = default;
    StructL(StructL &&) = default;
    StructL &operator=(StructL &&) = default;
		~StructL() = default;

		// return array of 0 and 1's which are 
		// represent elements
		virtual void setPos() override;

		virtual const std::array< std::array< size_t, 5 >, 5 > &getPos() const override;

		virtual void setFrstPos() override;
		virtual void setScndPos() override;
		virtual void setThrdPos() override;
		virtual void setFrthPos() override;
};

#endif
