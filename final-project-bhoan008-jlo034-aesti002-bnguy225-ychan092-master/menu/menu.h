#ifndef __MENU_HPP__
#define __MENU_HPP__

#include <iostream>
#include <string>
#include <cstdlib>
#include "../task.hpp"

using namespace std;


class Menu : public Task {

	private:
	Task* a;
	vector<Task*> user1;

	public:
	void DisplayMainMenuOptions();
	void showTask();
	void editTask();

};

#endif
