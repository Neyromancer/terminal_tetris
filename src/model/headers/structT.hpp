// structT.hpp
#ifndef _STRUCT_T_HPP_
#define _STRUCT_T_HPP_

#include "struct.hpp"

class StructT: public Struct {
	public:
		StructT(size_t = 1, size_t = 0, size_t = 0);
    StructT(const StructT &) = default;
    StructT &operator=(const StructT &) = default;
    StructT(StructT &&) = default;
    StructT &operator=(StructT &&) = default;
		~StructT() = default;

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
