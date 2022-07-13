#ifndef MAIN_MENU__H
#define MAIN_MENU_H

#include "task.hpp"
#include <vector>

#include "DateSort.hpp"
#include "PrioSort.hpp"
#include "TagSort.hpp"

using namespace std;

class MainMenu {
	private:
		vector<Task*> unsorted;
		vector<Task*> dates;
		vector<Task*> priorities;
		vector<Task*> tags;
		Sort* sortTarget = nullptr;

	public:
		void LoadTask();
		void DisplayAll();
		void DisplayByDue();
		void DisplayByTag();
		void showTask();
		void addTask();
		void editTask();
		void deleteTask();
		bool deleteTask(string title);
		void createNewUserFile(string userName);
		void outputOldUserFile(string userName);
		void saveTasksToCSV(string userName);
		Task* findTitle(vector<Task*>& taskVector, string key);
		//help functions
		void addTask(Task*);
		void editTitle();
		void editDesc();
		void editTag();
		void editPrio();
		void editDate();
		void copy(Task* lhs, Task* rhs);
		void printVector(vector<Task*>);

		//accessors
		vector<Task*> GetDates() {return dates;}
		vector<Task*> GetPriorities() {return priorities;}
		vector<Task*> GetTags() {return tags;}
		int getDateSize() {return dates.size();}
		int getPrioSize() {return priorities.size();}
		int getTagSize() {return tags.size();}
	
	
		//string getTitle() const{return 

		string getPrintedList(vector<Task*>);
	};

//
/*

#date: vector<task*>
#prio: vector<task*>
#tag: vector<task*>
#sortTarget: sort*
*/

#endif
