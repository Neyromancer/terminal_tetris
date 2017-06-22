// elements.hpp
#ifndef _STRUCT_HPP_
#define _STRUCT_HPP_

#include <array>

class Struct {
	public:
		Struct();
	virtual	~Struct();

		void setPosition( const size_t );
		size_t getPosition() const;
		
		void setCoordX( const size_t );
		size_t getCoordX() const;

		void setCoordY( const size_t );
		size_t getCoordY();
		
		void setStructCoord( const size_t x, const size_t y );

		void mvStructLeft();
		void mvStructRight();
		void mvStructUp();
		void mvStructDown();

		void setWidth( const size_t );
		size_t getWidth() const;

		void setHeight( const size_t );
		size_t getHeight() const;

		// return array of 0 and 1's which are 
		// represent elements
		virtual const std::array< std::array< char, 5 >, 5 > &displayStruct() const;
		virtual const std::array< std::array< char, 5 >, 5 > &frstPos() const = 0;
		virtual const std::array< std::array< char, 5 >, 5 > &scndPos() const = 0;
		virtual const std::array< std::array< char, 5 >, 5 > &thrdPos() const = 0;
		virtual const std::array< std::array< char, 5 >, 5 > &frthPos() const = 0;

	private:
		size_t elemPos;	// any element has 4 possible possitions
		size_t coordX;	// coord x of the top left corner
		size_t cootdY;	// coord y of the top left corner
		size_t width;	// element's width
		size_t height;	// element's height
		std::array< std::array< char, 5 >, 5 > element;	// stays for the field of 0's and 1's

};

#endif
