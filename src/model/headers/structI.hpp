// structI.hpp
#ifndef _STRUCT_I_HPP_
#define _STRUCT_I_HPP_

#include "struct.hpp"

class StructI: public Struct {
	public:
		StructI(size_t pos = 1, size_t x = 0, size_t y = 0);
    StructI(const StructI &) = default;
    StructI &operator=(const StructI &) = default;
    StructI(StructI &&) = default;
    StructI &operator=(StructI &&) = default;
		~StructI() = default;

		// return array of 0 and 1's which are 
		// represent elements
		virtual void setPos() override;
		virtual const std::array<std::array<size_t, 5>, 5> &getPos() const override;

		virtual void setFrstPos() override;
		virtual void setScndPos() override;
		virtual void setThrdPos() override;
		virtual void setFrthPos() override;
};

#endif
