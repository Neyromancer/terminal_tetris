// structS.hpp
#ifndef _STRUCT_S_HPP_
#define _STRUCT_S_HPP_

#include "struct.hpp"

class StructS: public Struct {
	public:
		StructS(size_t = 1, size_t = 0, size_t = 0);
    StructS(const StructS &) = default;
    StructS &operator=(const StructS &) = default;
    StructS(StructS &&) = default;
    StructS &operator=(StructS &&) = default;
		~StructS() = default;

		// return array of 0 and 1's which are 
		// represent elements
		virtual const std::array<std::array<size_t, 5>, 5> &getPos() const override;

		virtual void setPos() override;
		virtual void setFrstPos() override;
		virtual void setScndPos() override;
		virtual void setThrdPos() override;
		virtual void setFrthPos() override;

};

#endif
