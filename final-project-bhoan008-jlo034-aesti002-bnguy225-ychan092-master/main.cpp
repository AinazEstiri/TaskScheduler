#include <iostream>
#include <fstream>
#include <algorithm>
#include "date.h"
#include "MainMenu.cpp"
#include "task.hpp"
#include <string>
#define User MainMenu

using namespace std;

int displayMainMenuOptions(MainMenu& menu) {
	string option = "";
	while(option != "a" && option != "d" && option != "e" && option != "s" && option != "q") {
		cout<<"---------------------------------------"<<endl;
    		cout<<"|      What would you like to do?     |"<<endl;
	    	cout<<"|      a - Add a task     	      |"<<endl;
		cout<<"|      d - Delete a task              |"<<endl;
	    	cout<<"|      e - Edit a task                |"<<endl;
	    	cout<<"|      s - Show all tasks             |"<<endl;	
		cout<<"|      q - Close program              |"<<endl;				
		cout<<"---------------------------------------"<<endl;
		cin >> option;
		cin.ignore();
		transform(option.begin(), option.end(), option.begin(), ::tolower); /*makes cin result lowercase*/
		if(option != "a" && option != "d" && option != "e" && option != "s" && option != "q") {
			cout << "Please enter a correct input." << endl;
		}		
	}	
	if(option == "a") {
		menu.addTask();
	}
	if(option == "d") {
		menu.deleteTask();
	}
	if(option == "e") {
		menu.editTask();
	}
	if(option == "s") {
		menu.showTask();
	}
	if(option == "q") {
		return 1;
	}
}

string newUser(MainMenu& menu) {
	string userName = "";
        cout<<"---------------------------------------"<<endl;
	cout<<"|       Please enter a username       |"<<endl;
	cout<<"|          (case sensitive)           |"<<endl;
	cout<<"---------------------------------------"<<endl;
        cin >> userName;
        menu.createNewUserFile(userName);
	return userName;
}

string oldUser(MainMenu& menu) {
	string userName = "";
        cout<<"---------------------------------------"<<endl;
	cout<<"|       Please enter your username    |"<<endl;
	cout<<"|          (case sensitive)           |"<<endl;	
	cout<<"---------------------------------------"<<endl;
        cin >> userName;
        menu.outputOldUserFile(userName);
	return userName;
}

string userPrompt(MainMenu& menu) {
	string userName = "";
	string option = "";
	while(option != "y" && option != "n") {
		cout<<"---------------------------------------"<<endl;
    		cout<<"|           Are you a new user?       |"<<endl;
		cout<<"|           y - Yes                   |"<<endl;
		cout<<"|           n - No                    |"<<endl;
    		cout<<"---------------------------------------"<<endl;
		cin >> option;
		transform(option.begin(), option.end(), option.begin(), ::tolower); /*makes cin result lowercase*/
		if(option != "y" && option != "n") {
			cout << "Please enter a correct input." << endl;
		}	
	}
	if(option == "y"){
		userName = newUser(menu);
	}
	if(option == "n"){
		userName = oldUser(menu);
	}
	return userName;
}

int main() {
    cout<<"---------------------------------------"<<endl;
    cout<<"|           W E L C O M E             |"<<endl;
    cout<<"---------------------------------------"<<endl;	
    
    string userName = "";
    int quitProgram = 0; // 0 for continue, any other number for quit.
    MainMenu menu;
    userName = userPrompt(menu);
    while(quitProgram == 0) {
	quitProgram = displayMainMenuOptions(menu);
    }
	
    if(quitProgram == 1) {
	menu.saveTasksToCSV(userName);
	cout<<"---------------------------------------"<<endl;
	cout<<"|           G O O D B Y E             |"<<endl;
	cout<<"---------------------------------------"<<endl;
    }
    
    return 0;

}

