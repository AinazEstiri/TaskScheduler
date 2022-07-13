#ifndef SORT_H
#define SORT_H
#include "task.hpp"

class Sort {
	public:
	
	vector<Task*> virtual sort(vector<Task*> sortedVector, Task* newTask) = 0;
};


#endif
