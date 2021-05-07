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
#include "Food.h"
#include <iostream>

using namespace std;
namespace sdds {
	void Food::display()const {
		if (isValid()) {
			cout << "| ";
			cout.setf(ios::left);
			cout.width(30);
			cout.fill('.');
			cout.setf(ios::fixed);
			cout << food_name;
			cout << " | ";
			cout.setf(ios::right);
			cout.fill(' ');
			cout.width(4);
			cout << cal_num << " | ";
			cout.width(10);
			cout.unsetf(ios::right);
			cout.setf(ios::left);
			cout << when() << " |" << endl;
			cout.unsetf(ios::left);
		}
		else {
			cout << "| xxxxxxxxxxxxxxxxxxxxxxxxxxxxxx | xxxx | xxxxxxxxxx |" << endl;
		}
	}
	void Food::setName(const char* name) {
		strnCpy(food_name, name, 30);
	}
	
	
	void Food::setEmpty() {
		food_name[0] = '\0';
		cal_num = 0;
		time_consp = 0;
	}
	void Food::set(const char* name, int cal, int tofconsp) {
		if (name == nullptr || cal < 0 || cal > 3000 || tofconsp < 1 || tofconsp>4) {
			setEmpty();
		}
		else {
			setName(name);
			cal_num = cal;
			time_consp = tofconsp;
		}
	}
	bool Food::isValid()const {
		if (food_name[0] != '\0' && cal_num >= 0&& cal_num<=3000 && time_consp >0) {
			return true;
		}
		return false;
	}
	int Food::cals()const {
		return cal_num;
	}
	const char* Food::when()const {
		switch(time_consp) {
		case 1:
			return "Breakfast";
		case 2:
			return "Lunch";
		case 3:
			return "Dinner";
		case 4:
			return "Snack";
		default:
			return nullptr;
		}
	}
}
