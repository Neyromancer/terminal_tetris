// interface.hpp

#ifndef _INTERFACE_HPP_
#define _INTERFACE_HPP_

class Interface {
	public:
		Interface();
		~Interface();

		void displayInterface() const;

	private:
		void displayMainField( size_t ) const;
		void displayScoreField( size_t ) const;
		void displayLinesRemovedField( size_t ) const;
		void displayLevelField( size_t ) const;
		void displayNextPieceField( size_t ) const;
		void displayCommandField( size_t ) const;
};

#endif
