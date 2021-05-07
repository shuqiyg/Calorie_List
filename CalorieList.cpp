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
#include "CalorieList.h"

using namespace std;
namespace sdds {
	int CalorieList::totalCal()const {
		int total_cal = 0;
		int i;
		for (i = 0; i < size; i++) {
			total_cal += f_items[i].cals();
		}
		return total_cal;
	}
	void CalorieList::Title()const {
		cout << "+----------------------------------------------------+" << endl;
		if (isValid()) {
			cout << "| ";
			cout.setf(ios::left);
			cout.width(50);
			cout << " Daily Calorie Consumption";
			cout << " |" << endl;
			cout.unsetf(ios::left);
		}
		else {
			cout << "| Invalid Calorie Consumption list                   |" << endl;
		}
		cout << "+--------------------------------+------+------------+" << endl;
		cout << "| Food name                      | Cals | When       |" << endl;
		cout << "+--------------------------------+------+------------+" << endl;
	}
	void CalorieList::Footer()const {
		cout << "+--------------------------------+------+------------+" << endl;
		if (isValid()) {
			cout << "|    Total Calories for today:";
			cout.setf(ios::right);
			cout.width(9);
			cout << totalCal() << " |            |" << endl;
			cout.unsetf(ios::right);
			cout << "+----------------------------------------------------+" <<endl;
		}
		else {
			cout << "|    Invalid Calorie Consumption list                |" << endl;
			cout << "+----------------------------------------------------+" << endl;
		}
	}
	bool CalorieList::isValid()const {
		bool valid_cl = f_items != nullptr && size > 0;
		if (valid_cl) {
			int i;
			for (i = 0; i < size && valid_cl; i++) {
				valid_cl = f_items[i].isValid();
			}
		}
		return valid_cl;
	}
	void CalorieList::setEmpty() {
		f_items = nullptr;
	}
	void CalorieList::display()const {
		Title();
		int i;
		for (i = 0; i < size; i++) {
			f_items[i].display();
		}
		Footer();
	}
	void CalorieList::init(int food_num) {
		if (food_num > 0) {
			size = food_num;
			itemsAdded = 0;
			f_items = new Food[size];
			int i;
			for (i = 0; i < size; i++) {
				f_items[i].setEmpty();
			}
		}
		else {
			setEmpty();
		}
	}
	bool CalorieList::add(const char* item_name, int calories, int when){
		if (size > itemsAdded) {
			f_items[itemsAdded].set(item_name, calories, when);
			itemsAdded++;
			return true;
		}
		return false;
	}
	void CalorieList::deallocate() {
		for (int i = 0; i < size; i++)
		{
			f_items[i].setEmpty();
		}
		delete[] f_items;
		f_items = nullptr;
	}
}