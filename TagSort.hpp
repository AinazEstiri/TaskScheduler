#ifndef TAGSORT_H
#define TAGSORT_H

#include "Sort.hpp"

class TagSort : public Sort {
        
	public:

        vector<Task*> sort(vector<Task*> sortedVector, Task* newTask) {
		int compare = 0;

		string newTag = newTask->getTag();
		string oldTag = "";
               /*sorts by tag, alphabetically*/
                for (int i = 0; i < sortedVector.size(); ++i) {
                        oldTag = sortedVector.at(i)->getTag();
			compare = newTag.compare(oldTag); //compares newTask tag alphabetically with each element of the vector.
			if (compare < 0) {			
                                sortedVector.insert(sortedVector.begin() + i, newTask);
                                return sortedVector;
                        }
                }
	cout << endl;

                sortedVector.push_back(newTask);
                return sortedVector;
        }

	
};


#endif

