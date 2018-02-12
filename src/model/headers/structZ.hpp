// structT.hpp
#ifndef _STRUCT_Z_HPP_
#define _STRUCT_Z_HPP_

#include "struct.hpp"

class StructZ: public Struct {
	public:
		StructZ(size_t = 1, size_t = 0, size_t = 0);
    StructZ(const StructZ &) = default;
    StructZ &operator=(const StructZ &) = default;
    StructZ(StructZ &&) = default;
    StructZ &operator=(StructZ &&) = default;
		~StructZ() = default;

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
