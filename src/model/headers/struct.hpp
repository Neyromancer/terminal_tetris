// elements.hpp
#ifndef _STRUCT_HPP_
#define _STRUCT_HPP_

#include <array>
#include <stdexcept>

class Struct {
	public:
		Struct(size_t = 1, size_t = 0, size_t = 0);
	  virtual	~Struct() = default;

		void setPosition(const size_t);
		size_t getPosition() const;
	
		// coord represent 1st cell in the array
		// which stays for the tetromino	
		void setCoordX(const size_t);
		size_t getCoordX() const;

		void setCoordY(const size_t);
		size_t getCoordY() const;
		
		void setStructCoord(const size_t x, const size_t y);
/*
		void mvStructLeft();
		void mvStructRight();
		void mvStructUp();
		void mvStructDown();
*/
		void setWidth(const size_t);
		/*virtual */void setWidth() /*= 0*/;
		size_t getWidth() const;

		void setHeight(const size_t);
		/*virtual */void setHeight() /*= 0*/;
		size_t getHeight() const;

		// return array of 0 and 1's which are 
		// represent elements
		virtual void setPos() = 0;

		virtual const std::array< std::array<size_t, 5>, 5> &getPos() const = 0;

		virtual void setFrstPos() = 0;
		virtual void setScndPos() = 0;
		virtual void setThrdPos() = 0;
		virtual void setFrthPos() = 0;

	protected:
		size_t elemPos;	// any element has 4 possible possitions
		size_t coordX;	// coord x of the top left corner
		size_t coordY;	// coord y of the top left corner
		size_t width;	// element's width
		size_t height;	// element's height
		std::array< std::array<size_t, 5>, 5> element;	// stays for the field of 0's and 1's

};

#endif
