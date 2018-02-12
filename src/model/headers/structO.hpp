// structO.hpp
#ifndef _STRUCT_O_HPP_
#define _STRUCT_O_HPP_

#include "struct.hpp"

class StructO: public Struct {
	public:
		StructO(size_t = 1, size_t = 0, size_t = 0);
    StructO(const StructO &) = default;
    StructO &operator=(const StructO &) = default;
    StructO(StructO &&) = default;
    StructO &operator=(StructO &&) = default;
		~StructO() = default;

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
