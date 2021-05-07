/* W03 DIY
   Name: Shuqi Yang
   Std ID: 132162207
   Email: syang136@myseneca.ca
   Date: 02-05-2021
   -------------------------------------------------------
   I have done all the coding by myself and only copied the
   code that my professor provided to complete my workshops
   and assignments.
 */
#ifndef CALORIELIST_H_
#define CALORIELIST_H_
//#include "cstring.h"
#include "Food.h"
#include <iostream>

namespace sdds {
	class CalorieList {
		Food* f_items;
		int size;
		int itemsAdded;
		int totalCal()const;
		void Title()const;
		void Footer()const;
		bool isValid()const;
		void setEmpty();

	public:
		void display()const;
		void init(int num_food);
		bool add(const char* item_name, int calories, int when);
		void deallocate();
	};


}


#endif
