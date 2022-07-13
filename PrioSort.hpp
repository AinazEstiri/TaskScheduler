#ifndef PRIOSORT_H
#define PRIOSORT_H

#include "Sort.hpp"

class PrioSort : public Sort {
        public:

        vector<Task*> sort(vector<Task*> sortedVector, Task* newTask) {

                /*checks each task based on priority. 3 highest priority, 1 lowest priority*/
                for (int i = 0; i < sortedVector.size(); ++i) {
                        if (newTask->getPrio() > sortedVector.at(i)->getPrio()) {
                                sortedVector.insert(sortedVector.begin() + i, newTask);
                                return sortedVector;
                        }
                }

                sortedVector.push_back(newTask);
                return sortedVector;
        }
};


#endif

