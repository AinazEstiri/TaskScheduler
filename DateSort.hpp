#ifndef DATESORT_H
#define DATESORT_H

#include "Sort.hpp"

class DateSort : public Sort {
	public:

	vector<Task*> sort(vector<Task*> sortedVector, Task* newTask) {
		int year = newTask->getYear() ;
		int month = newTask->getMonth() ;
		int day = newTask->getDay();
		bool inserted = false;
		
		for (int i = 0; i < sortedVector.size(); ++i) {
			if (year < sortedVector.at(i)->getYear()) {
				sortedVector.insert(sortedVector.begin() + i, newTask);
				return sortedVector;
			}
			else if (month < sortedVector.at(i)->getMonth()) {
				sortedVector.insert(sortedVector.begin() + i, newTask);
				return sortedVector;
			}
			else if (day < sortedVector.at(i)->getDay()) {
				 sortedVector.insert(sortedVector.begin() +i, newTask);
				return sortedVector;
			}
		}

		sortedVector.push_back(newTask);
		return sortedVector;		
	}
};


#endif
