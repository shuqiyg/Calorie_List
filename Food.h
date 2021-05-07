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

#ifndef _FOOD_H_
#define _FOOD_H_
#include "cstring.h"

namespace sdds {
	class Food {
		char food_name[31];
		int cal_num;
		int time_consp;
		void setName(const char* name);
	public:
		void display()const;
		void setEmpty();
		void set(const char* name, int cal, int tofconsp);
		bool isValid()const;
		int cals()const;
		const char* when()const;

	};
}




#endif