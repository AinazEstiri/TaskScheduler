#include <iostream>
#include <string>
#include "menu.h"

using namespace std;

void Menu::DisplayMainMenuOptions() {
	string MenuOption;
	while(MenuOption != "Exit") {
		cout << "Enter 'A'(Without the 's) to show all of your tasks" << endl;
		cout << "Enter 'B' (Without the 's) to add a task" << endl;
		cout << "Enter 'C' (Without the 's) to delete a task" << endl;
		cout << "Enter 'D' (Without the 's) to edit a task" << endl;
		cout << "Enter 'Exit' (Without the 's) to exit the Task Manager" << endl;
		cout << "====================  ====================" << endl;
		cout << endl;
		cin >> MenuOption;
		cout << endl;
		if (MenuOption == "A") {
//			showTasks();
		}
		else if(MenuOption == "B") {
//			addTask();
		}
		else if(MenuOption == "C") {
//			deleteTask();
		}
		else if(MenuOption == "D") {
			editTask();
		}
		else if(MenuOption == "Exit") {
			cout << "Goodbye!" << endl;
			cout << endl;
		}
		else {
			cout << "Invalid Input" << endl;
			cout << endl;
		}
	}	
}

void Menu::editTask() {

        string editOp;

        cout<<"-----------------------------------------------"<<endl;
        cout<<"|         What would you like to edit?         |"<<endl;
        cout<<"|         A. Title                             |"<<endl;
        cout<<"|         B. Description                       |"<<endl;
        cout<<"|         C. Tag                               |"<<endl;
        cout<<"|         D. Priority                          |"<<endl;
        cout<<"|         E. Date                              |"<<endl;
	cout<<"|	Press Q to Exit.  		      |"<<endl;
        cout<<"------------------------------------------------"<<endl;

        cout<< endl;
        cin>>editOp;
        cout<< endl;

        if (editOp == "A") {
                editTitle(v);
        }
        else if (editOp == "B") {
                editDesc(v);
        }
        else if (editOp == "C") {
		editTag(vector<task*> v);
	}
	else if (editOp == "D") {
		editPrio(vector<task*> v);
	}
	else if (editOp == "E") {
		editDate(vector<task*> v);
	}
	else if (editOp == "Q") {
		cout << "Done." <<endl;
	}
	else {
		cout << "Invalid Input" << endl;
		editTask();
	}
}


