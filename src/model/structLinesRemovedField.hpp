// structLinesRemovedField.hpp
#ifndef _STRUCT_LINES_REMOVED_FIELD_HPP_
#define _STRUCT_LINES_REMOVED_FIELD_HPP_

#include <string>

#include "structMainField.hpp"

class StructLinesRemovedField: public StructMainField {
	public:
		StructLinesRemovedField( size_t = 7, size_t = 7, size_t = 0 );
		~StructLinesRemovedField();
	
		void setRemovedLines( const size_t );
		size_t getRemovedLines() const;

		const std::string &getFieldName() const;	
	private:
		size_t removedLines;
		static const std::string fieldName = "LINES";
};

#endif
