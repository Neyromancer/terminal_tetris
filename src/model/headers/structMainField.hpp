// structMainField.hpp
#ifndef _STRUCT_MAIN_FIELD_HPP_
#define _STRUCT_MAIN_FIELD_HPP_

#include <array>

class StructMainField {
	public:
		StructMainField( size_t = 24, size_t = 11 );
		~StructMainField(){}
		
		const std::array< std::array< size_t, 24 >, 11 > &getField() const;
		void setField( size_t row, size_t cell, size_t value /* = 0 or 1 */ );

		void setWidth( const size_t );
		size_t getWidth() const;

		void setHeight( const size_t );
		size_t getHeight() const;

		bool isAreaOccupied( size_t, size_t ) const;

	private:
		void fillField();
		size_t width;	// field's width
		size_t height;	// field's height
		std::array< std::array< size_t, 24 >, 11 > element;	// stays for the field of 0's and 1's

};

#endif
