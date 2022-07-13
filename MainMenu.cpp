#include "MainMenu.hpp"
#include "ShowTask.hpp"
#include <iostream>
#include <string>
#include <cctype>
#include <algorithm>
#include "task.hpp"
#include <cstdlib>
#include <fstream>
#include <sstream>


using namespace std;


void MainMenu::createNewUserFile(string userName) {
	string fileName = "AllUserNames/" + userName + ".csv";
        fstream file;
        file.open(fileName, ios::out);
        if(!file.is_open()){
                cerr << "Failed to create new user file " << fileName << '\n';
        }
        else {
		cout<< fileName << " is created!" << endl;
                file.close();
        }
}

void MainMenu::outputOldUserFile(string userName) {
	string	fileName = "AllUserNames/" + userName + ".csv";
        fstream file;
        file.open(fileName, ios::in);
        if(!file.is_open()){
                cerr << "Failed to open old user file " << fileName << '\n';
        }
        else {		
		cout << fileName << " has been accessed!" << endl;
		string title;
		int prio;
		string tag;
		string desc;
		int day;
		int month;
		int year;

		vector<string> row;
		string word, temp;		
		while (getline(file, temp)) {
			row.clear();
			stringstream s(temp);
			while (getline(s, word, ',')) {
				row.push_back(word);
			}
			title = row[0];
			prio = stoi(row[1]);
			tag = row[2];
			desc = row[3];
			day = stoi(row[4]);
			month = stoi(row[5]);
			year = stoi(row[6]);
			Task* newTask = new Task(title, desc, prio, tag);
			newTask->setDay(day);
			newTask->setMonth(month);
			newTask->setYear(year);
			addTask(newTask);
		
		}
	}
		cout << userName << "'s tasks has been sucessfully loaded!" << endl;
        	file.close();
}

void MainMenu::saveTasksToCSV(string userName) {
	string fileName = "AllUserNames/" + userName + ".csv";
        fstream file;
        file.open(fileName, ios::out);
        if(!file.is_open()){
                cerr << "Failed to open csv file to save tasks in " << fileName << '\n';
        }
        else {
                for(int i = 0; i < unsorted.size(); i++) {
                        file << unsorted.at(i)->getTitle() << ',';
                        file << unsorted.at(i)->getPrio() << ',';
                        file << unsorted.at(i)->getTag() << ',';
                        file << unsorted.at(i)->getDesc() << ',';
                        file << unsorted.at(i)->getDay() << ',';
                        file << unsorted.at(i)->getMonth() << ',';
                        file << unsorted.at(i)->getYear() << endl;
                }
		file.close();
		cout << "Tasks successfully saved in " << fileName << endl;
        }		
}

void MainMenu::deleteTask() {
	string title;	
	bool deleted = false;
	cout<<"---------------------------------------"<<endl;
	cout<<"|  Enter Title of Task for Deletion:   |"<<endl;
	cout<<"---------------------------------------"<<endl;
	
	getline(cin,title);
	//deletes what pointer is pointing too, then erases the pointer from vector. 
	deleted = this->deleteTask(title);
	
	if (deleted) {
		cout<<"---------------------------------------"<<endl;
                cout<<"|         ♪♪ Task Deleted!♪♪           |"<<endl;
                cout<<"---------------------------------------"<<endl;

		
	}
	else {
 
		cout<<"-------------------------------------------------"<<endl;
                cout<<"| Task not found. press enter to return to menu.|"<<endl;
                cout<<"-------------------------------------------------"<<endl;
	}
//this->title= title;
//cin.ignore();
//

}

bool MainMenu::deleteTask(string key) {


		Task* erasedTask = nullptr;
	   
		erasedTask = findTitle(dates, key);
		erasedTask = findTitle(priorities, key);
		erasedTask = findTitle(tags, key);
		erasedTask = findTitle(unsorted, key);	
        
	delete erasedTask;

	return true;
	
}

//finds title/task in the  vector, and then erases from within that vector. **Does not delete pointer**
Task* MainMenu::findTitle(vector<Task*>& taskVector, string key) {
                
	string currentTitle = "";
	bool erased = "false";
	Task* erasedTask = nullptr;
		for (int i = 0; i < taskVector.size(); i++) {
                currentTitle = taskVector.at(i)->getTitle();
                if (currentTitle.find(key) != string::npos) {
			erasedTask = taskVector.at(i);
                        taskVector.erase(taskVector.begin()+i);
                        erased = true;
                }

        }
	return erasedTask;	
}

void MainMenu::addTask() {
	string input="";
	int month=0;
	int day=0;
	int year=0;

	Task* newTask = new Task();
	string title = "";
	/*TITLE*/
	cout<<"---------------------------------------"<<endl;
	cout<<"|         Enter Title of Task:         |"<<endl;
	cout<<"---------------------------------------"<<endl;
	
	//cin.ignore();
	getline(cin,title);

	if (title == "\n") {
	    cout<<"---------------------------------------"<<endl;
	    cout<<"|         Please Enter A Title         |"<<endl;
	    cout<<"---------------------------------------"<<endl;
	    getline(cin,title);
	}
	cout<<"title set:"<<title<<endl;
	newTask->setTitle(title);
	
	string discription = ""; //you spelled this wrong lol,staying with the wrong spelling. -BH
	/*DISCRIPTION*/
	cout<<"---------------------------------------"<<endl;
	cout<<"|         Description for task?        |"<<endl;
	cout<<"|        (Press Enter for none)        |"<<endl;
	cout<<"---------------------------------------"<<endl;
	
	getline(cin,discription);
	newTask->setDesc(discription);
	
	cout<<"set description:"<<discription<<endl;

	string temp = "";

	/*PRIORITY*/
	cout<<"---------------------------------------"<<endl;
	cout<<"|          Priority for task?          |"<<endl;
	cout<<"|          Pick 1 for least important  |"<<endl;
	cout<<"|          Pick 2 for important        |"<<endl;
	cout<<"|          Pick 3 for most important   |"<<endl;
	cout<<"|         (Press n for not important)  |"<<endl;
	cout<<"---------------------------------------"<<endl;
	cin>> temp;
	while(temp!="1" && temp!="2" && temp!="3" && temp!="n"){ 
	    	cout<<"---------------------------------------"<<endl;
	    	cout<<"|          Invalid Input:              |"<<endl;
	    	cout<<"|          Pick 1 for least important  |"<<endl;
     		cout<<"|          Pick 2 for important        |"<<endl;
        	cout<<"|          Pick 3 for most important   |"<<endl;
        	cout<<"|         (Press n for not important)  |"<<endl;
		cout<<"---------------------------------------"<<endl;
	    cin>> temp;
	    cin.ignore();
	}
	if(temp== "1"){
	        newTask->setPrio(1);
	        cout<<"entered:"<<temp<<endl;
	    }
	if(temp== "2"){
	        newTask->setPrio(2);
	        cout<<"entered:"<<temp<<endl;
	    }
	if(temp== "3"){
	        newTask->setPrio(3);
	        cout<<"entered:"<<temp<<endl;
	    }
	if(temp== "n"){
	        cout<<"entered:"<<temp<<endl;
	    }

	string tag = "";


	/*TAG*/
	cout<<"---------------------------------------"<<endl;
	cout<<"|          Tag the task?               |"<<endl;
	cout<<"|          h - homework                |"<<endl;
	cout<<"|          s - study                   |"<<endl;
	cout<<"|          p - personal                |"<<endl;
	cout<<"|          b - business                |"<<endl;
	cout<<"|          e - event                   |"<<endl;
	cout<<"|          w - work                    |"<<endl;
	cout<<"|          o - other                   |"<<endl;
	cout<<"|         (Press n for no tag)         |"<<endl;
	cout<<"---------------------------------------"<<endl;

	cin>> tag;

	transform(tag.begin(), tag.end(), tag.begin(), ::tolower); /*makes cin result lowercase*/

	while(tag != "h" && tag !="s" && tag !="p" && tag !="b" && tag !="e" && tag !="w" && tag !="o" && tag !="n"){
		cout<<"---------------------------------------"<<endl;
		cout<<"|      Enter the correct letter        |"<<endl;
		cout<<"|          h - homework                |"<<endl;
		cout<<"|          s - study                   |"<<endl;
		cout<<"|          p - personal                |"<<endl;
		cout<<"|          b - business                |"<<endl;
		cout<<"|          e - event                   |"<<endl;
		cout<<"|          w - work                    |"<<endl;
		cout<<"|          o - other                   |"<<endl;
		cout<<"|          Press n for no tag          |"<<endl;
		cout<<"---------------------------------------"<<endl;

		cin>> tag;

		transform(tag.begin(), tag.end(), tag.begin(), ::tolower); /*makes cin result lowercase*/

	}

	if(tag== "h"){
        	newTask->setTag("Homework");
	        cout<<"entered:"<<tag<<endl;
	    }
	if(tag== "s"){
	        newTask->setTag("Study");
	        cout<<"entered:"<<tag<<endl;
	    }
	if(tag== "p"){
	        newTask->setTag("Personal");
	        cout<<"entered:"<<tag<<endl;
	    }
	if(tag== "b"){
	        newTask->setTag("Business");
	        cout<<"entered:"<<tag<<endl;
	    }
	if(tag== "e"){
	        newTask->setTag("Event");
	        cout<<"entered:"<<tag<<endl;
	    }
	if(tag== "w"){
	        newTask->setTag("Work");
	        cout<<"entered:"<<tag<<endl;
	    }
	if(tag== "o"){
	        newTask->setTag("Other");
	        cout<<"entered:"<<tag<<endl;
	    }
	if(tag== "n"){
	        cout<<"entered:"<<tag<<endl;
	    }
	

	/*DATE*/
	cout<<"---------------------------------------"<<endl;
	cout<<"|           Need a due date?          |"<<endl;
	cout<<"|               y- yes                |"<<endl;
	cout<<"|               n- no                 |"<<endl;
	cout<<"---------------------------------------"<<endl;
	cin>> input;

	while(input!= "y" && input!= "n"){
		cout<<"---------------------------------------"<<endl;
		cout<<"|           Need a due date?          |"<<endl;
		cout<<"|             Enter y- yes            |"<<endl;
		cout<<"|             Enter n- no             |"<<endl;
		cout<<"---------------------------------------"<<endl;
		cin>> input;
	}

	if(input== "y"){ 
	
	    /*create a default date set to 01/01/2022*/
	    cout<<"entered yes (yes date)"<<endl;
	    cout<<"---------------------------------------"<<endl;
	    cout<<"|      Input month in form (xx)       |"<<endl;
	    cout<<"|        Example: July--> 07          |"<<endl;
	    cout<<"---------------------------------------"<<endl;
	    cin>> month;
	    cout<< "Month:"<<month<<endl;
	    newTask->setMonth(month);
	  
	    cout<<"---------------------------------------"<<endl;
	    cout<<"|      Input day in form (xx)          |"<<endl;
	    cout<<"|        Example: day--> 28            |"<<endl;
	    cout<<"---------------------------------------"<<endl;
	    cin>> day;
	    cout<< "Day:"<<day<<endl;
	    newTask->setDay(day);
	    
	    cout<<"---------------------------------------"<<endl;
	    cout<<"|       Input year in form (xxxx)      |"<<endl;
	    cout<<"|      Example: year 2022--> 2022      |"<<endl;
	    cout<<"---------------------------------------"<<endl;
	    cin>>year;
	    cout<< "Year:"<<year<<endl;
	    newTask->setYear(year);
   
	}
	if(input== "n"){
	    cout<<"entered:"<<input<<endl;
	}
	
	addTask(newTask);

}

void MainMenu::addTask(Task* newTask) {
	
	unsorted.push_back(newTask);
	
	sortTarget = new DateSort();
	dates = sortTarget->sort(dates, newTask);
	delete sortTarget; //Example Unit Test: Check if vector has an element or not.

	sortTarget = new PrioSort();
        priorities = sortTarget->sort(priorities, newTask);
	delete sortTarget; //Example Unit Test: Check if vector has an element or not.


	sortTarget = new TagSort();
        tags = sortTarget->sort(tags, newTask);
        delete sortTarget;

}




void MainMenu::showTask() {
 	cout << "--------------------------------------------------------------------------------" << endl;
	cout << "| Would you like to display your tasks in order by dates, priorities, or tags? |" << endl;
	cout << "|            Enter 1 for dates, 2 for priorities, 3 for tags.                  |" << endl; 
	cout << "|          Enter 0 if you would like to print by date added. 	               |" << endl;
	cout << "--------------------------------------------------------------------------------" << endl;
	int input;
	cin >> input;
	cout << endl;
		
	while(input != 0 && input != 1 && input != 2 && input != 3) {
		cout<<"---------------------------------------"<<endl;
    		cout<<"| Please Enter a Valid Input (0/1/2/3)|"<<endl;
    		cout<<"---------------------------------------"<<endl;
		
		cin >> input;
		cout << endl;
	}

	if (input == 0) {
		printVector(unsorted);
	}
	else if (input == 1){
		printVector(dates);
	}
	else if (input == 2) {
		printVector(priorities);
	}
	else {
		printVector(tags);
	}

}

string MainMenu::getPrintedList(vector<Task*> toPrint) {
	string output = "----------------------------\n";
	bool dueDateExists = true;
	bool prioExists = true;
	bool tagExists = true;
	bool descExists = true;
	for(int i = 0; i < toPrint.size(); i++) {
	
	string currentTask = to_string(i + 1);
	
	if(toPrint.at(i)->getDay() == -01 && toPrint.at(i)->getMonth() == 01 && toPrint.at(i)->getYear() == 2022) {
	dueDateExists = false;
	}
	if(toPrint.at(i)->getPrio() ==-1) {
	prioExists = false;
	}
	if(toPrint.at(i)->getTag() == "N/A") {
	tagExists = false;
	}
	if(toPrint.at(i)->getDesc() == "") {
	descExists = false;
	}


	output += currentTask + ") " + toPrint.at(i)->getTitle();
	if(dueDateExists) {
	output += "\nDue Date(mm/dd/yyyy): " + to_string(toPrint.at(i)->getMonth()) + "/" + to_string(toPrint.at(i)->getDay()) + "/" + to_string(toPrint.at(i)->getYear());
	} 

	
	if(prioExists) {
	output +="\nPrio: " + to_string(toPrint.at(i)->getPrio());
	} 

	if(tagExists) {
		if(prioExists) {
		output += "|Tag: " + toPrint.at(i)->getTag();
		} else {
		output += "\nTag: " + toPrint.at(i)->getTag();
		}
	}

	if(descExists) {
		output+= "\nDesc:" + toPrint.at(i)->getDesc();
	}
	
	output += "\n----------------------------\n";
	

	}
	return output;
}

void MainMenu::printVector(vector<Task*> toPrint) {
	cout << getPrintedList(toPrint);
}


//EDIT TASK: YENNA
void MainMenu::editTask() {

        string editOp;

        cout<<"--------------------------------------------"<<endl;
        cout<<"|       What would you like to edit?       |"<<endl;
        cout<<"|         A. Title                         |"<<endl;
        cout<<"|         B. Description                   |"<<endl;
        cout<<"|         C. Tag                           |"<<endl;
        cout<<"|         D. Priority                      |"<<endl;
        cout<<"|         E. Date                          |"<<endl;
	cout<<"|       Press Q to Exit.                   |"<<endl;
        cout<<"---------------------------------------------"<<endl;

        cin>>editOp;
	cout<< endl;

        if (editOp == "A" || editOp == "a") {
                editTitle();
        }
        else if (editOp == "B" || editOp == "b") {
                editDesc();
        }
        else if (editOp == "C" || editOp == "c") {
		editTag();
	}
	else if (editOp == "D" || editOp == "d" ) {
		editPrio();
	}
	else if (editOp == "E" || editOp == "e" ) {
		editDate();
	}
	else if (editOp == "Q" || editOp == "q" ) {
		cout << "Exited Task Editor" <<endl;
	}
	else {
		cout << "Invalid Input. Please choose an letter option OR press Q" << endl;
		editTask();
	}
}

void MainMenu::editTitle() {
	
        cout<<"--------------------------------------------------------------------"<<endl;
        cout<<"|      Please enter the title the task you would like to edit.     |"<<endl;
        cout<<"--------------------------------------------------------------------"<<endl;

	int index = 0;
	bool isMatch = false;
	string userTitle;

//	cout << getPrintedList(GetDates()) << endl;
	printVector(priorities);

        cin.ignore();
        getline(cin, userTitle);
        cout<< endl;
	
	for (int i = 0; i < dates.size(); i++) {
		if (dates.at(i)->getTitle() == userTitle) {
			index = i;
                        isMatch = true;
                }
        }

	while (isMatch == false)
	{
        	cout<<"-----------------------------------------------"<<endl;
        	cout<<"|      TITLE NOT FOUND. Please try again.      |"<<endl;
        	cout<<"------------------------------------------------"<<endl;
		cout << getPrintedList(GetDates()) << endl;

        	getline(cin, userTitle);
        	cout<< endl;
 
		for (int i = 0; i < dates.size(); i++) {
                	if (dates.at(i)->getTitle() == userTitle) {
                        	index = i;
                        	isMatch = true;	
			}
		}
	}	

        cout<<"-----------------------------------------------"<<endl;
        cout<<"|     What would you like to change it to?     |"<<endl;
        cout<<"------------------------------------------------"<<endl;

	string userEdit;
	getline(cin, userEdit);

	Task* editTask = new Task(); //new task object
	copy(editTask, dates.at(index)); //copy constructor
	editTask->setTitle(userEdit); //MAKE CHANGE
	
	deleteTask(userTitle); //deletes old task
	addTask(editTask); //sorts edited task into vectors

	cout << "Okay. " << userTitle << " has been changed to " << userEdit << "." <<  endl;
//	cout << getPrintedList(GetDates()) << endl;
	printVector(priorities);
		
}

void  MainMenu::copy(Task* lhs, Task* rhs) {

        lhs->setTitle(rhs->getTitle());
        lhs->setDesc(rhs->getDesc());
        lhs->setPrio(rhs->getPrio());
        lhs->setTag(rhs->getTag());
        lhs->setMonth(rhs->getMonth());
        lhs->setDay(rhs->getDay());
        lhs->setYear(rhs->getYear());

}


void MainMenu::editDesc() {

        cout<<"--------------------------------------------------------------------"<<endl;
        cout<<"|      Please enter the title the task you would like to edit.     |"<<endl;
        cout<<"--------------------------------------------------------------------"<<endl;

	int index = 0;
	bool isMatch = false;
	string userTitle;

	cout << getPrintedList(GetDates()) << endl;

        cin.ignore();
        getline(cin, userTitle);
        cout<< endl;

	for (int i = 0; i < dates.size(); i++) {
		if (dates.at(i)->getTitle() == userTitle) {
			index = i;
                        isMatch = true;
                }
        }

	while (isMatch == false)
	{
        	cout<<"-------------------------------------------------------------------------------------"<<endl;
        	cout<<"|      TASK NOT FOUND. Please enter the title of the task you would like to edit.    |"<<endl;
        	cout<<"--------------------------------------------------------------------------------------"<<endl;
		cout << getPrintedList(GetDates()) << endl;

        	getline(cin, userTitle);
        	cout<< endl;
 
		for (int i = 0; i < dates.size(); i++) {
                	if (dates.at(i)->getTitle() == userTitle) {
                        	index = i;
                        	isMatch = true;	
			}
		}
	}

        cout<<"-------------------------------------------"<<endl;
        cout<<"|     Please enter a new description.     |"<<endl;
        cout<<"--------------------------------------------"<<endl;

        string userEdit;
        getline(cin, userEdit);

	Task* editTask = new Task();
	copy(editTask, dates.at(index));
	
	deleteTask(dates.at(index)->getTitle());

	editTask->setDesc(userEdit);

	addTask(editTask);

	cout << "Okay. Description for " << userTitle << " has been changed to " << dates.at(index)->getDesc() << "." <<  endl;
	cout << getPrintedList(GetDates()) << endl;

}
void MainMenu::editTag() {

        cout<<"--------------------------------------------------------------------"<<endl;
        cout<<"|      Please enter the title the task you would like to edit.     |"<<endl;
        cout<<"--------------------------------------------------------------------"<<endl;

	int index = 0;
	bool isMatch = false;
	string userTitle;	

	cout << getPrintedList(GetDates()) << endl;

        cin.ignore();
        getline(cin, userTitle);
        cout<< endl;

	for (int i = 0; i < dates.size(); i++) {
		if (dates.at(i)->getTitle() == userTitle) {
			index = i;
                        isMatch = true;
                }
        }

	while (isMatch == false)
	{
        	cout<<"-----------------------------------------------------------------------------------------"<<endl;
        	cout<<"|      TITLE NOT FOUND. Please enter the title of the task you would like to edit.      |"<<endl;
        	cout<<"-----------------------------------------------------------------------------------------"<<endl;
		cout << getPrintedList(tags) << endl;

        	getline(cin, userTitle);
        	cout<< endl;
 
		for (int i = 0; i < dates.size(); i++) {
                	if (dates.at(i)->getTitle() == userTitle) {
                        	index = i;
                        	isMatch = true;	
			}
		}
	}

        cout<<"-----------------------------------"<<endl;
        cout<<"|     Please enter a new tag.     |"<<endl;
        cout<<"------------------------------------"<<endl;

        string userEdit;
        getline(cin, userEdit);

	Task* editTask = new Task();
	copy(editTask, dates.at(index));
	editTask->setTag(userEdit);

	deleteTask(dates.at(index)->getTitle());
	addTask(editTask);

        cout << "Okay. Tag for " << userTitle << " has been changed to " <<  dates.at(index)->getTag() << "." << endl;
	cout << getPrintedList(GetDates()) << endl;
}

void MainMenu::editPrio() {

        cout<<"--------------------------------------------------------------------"<<endl;
        cout<<"|      Please enter the title the task you would like to edit.     |"<<endl;
        cout<<"--------------------------------------------------------------------"<<endl;

	cout << getPrintedList(GetDates()) << endl;

        int index = 0;
        bool isMatch = false;
        string userTitle;

        cin.ignore();
        getline(cin, userTitle);
        cout<< endl;

        for (int i = 0; i < dates.size(); i++) {
                if (dates.at(i)->getTitle() == userTitle) {
                        index = i;
                        isMatch = true;
                }
        }

        while (isMatch == false)
        {
                cout<<"-----------------------------------------------------------------------------------------"<<endl;
                cout<<"|      TITLE NOT FOUND. Please enter the title of the task you would like to edit.      |"<<endl;
                cout<<"-----------------------------------------------------------------------------------------"<<endl;
                cout << getPrintedList(tags) << endl;

                getline(cin, userTitle);
                cout<< endl;

                for (int i = 0; i < dates.size(); i++) {
                        if (dates.at(i)->getTitle() == userTitle) {
                                index = i;
                                isMatch = true;
                        }
                }
        }
	
	cout<<"-------------------------------------"<<endl;
	cout<<"|      Enter a new priority:       |"<<endl;
	cout<<"|        1. least urgent           |"<<endl;
	cout<<"|        2. urgent                 |"<<endl;
	cout<<"|        3. most urgent            |"<<endl;
	cout<<"|        0. no urgency             |"<<endl;
	cout<<"-------------------------------------"<<endl;
	
	string temp;
	cin>> temp;

	while(temp!="1" && temp!="2" && temp!="3" && temp!="0") { 
   	cout<<"-------------------------------------"<<endl;
        cout<<"|        !Invalid Input!           |"<<endl;
	cout<<"|      Enter a new priority:       |"<<endl;
        cout<<"|        1. least urgent           |"<<endl;
        cout<<"|        2. urgent                 |"<<endl;
        cout<<"|        3. most urgent            |"<<endl;
        cout<<"|        0. no urgency             |"<<endl;
        cout<<"-------------------------------------"<<endl;
	cin>> temp;
    	cin.ignore();

	}

	if (temp == "1") { 
        	cout<<"entered: 1. least urgent" << endl;

        	for (int i = 0; i < dates.size(); i++) {
                	if (dates.at(i)->getTitle() == userTitle) {
//                        	dates.at(i)->setPrio(1);
                        	index = i;
                	}	

		}
		
		Task* editTask = new Task();
   	        copy(editTask, dates.at(index));
        	editTask->setPrio(1);

        	deleteTask(dates.at(index)->getTitle());
        	addTask(editTask);	
	}

        if (temp == "2") {
                cout<<"entered: 2. urgent"<< endl;


                for (int i = 0; i < dates.size(); i++) {
                        if (dates.at(i)->getTitle() == userTitle) {
//                                dates.at(i)->setPrio(2);
                                index = i;
                        }
                }

                Task* editTask = new Task();
                copy(editTask, dates.at(index));
                editTask->setPrio(2);

                deleteTask(dates.at(index)->getTitle());
                addTask(editTask);
        }

        if (temp == "3") {
                cout<<"entered: 3. most urgent"<< endl;


                for (int i = 0; i < dates.size(); i++) {
                        if (dates.at(i)->getTitle() == userTitle) {
                                dates.at(i)->setPrio(3);
                                index = i;
                        }
                }

		Task* editTask = new Task();
                copy(editTask, dates.at(index));
                editTask->setPrio(3);

                deleteTask(dates.at(index)->getTitle());
                addTask(editTask);
        }

        if (temp == "0") {
                cout<<"entered: 0. not urgent "<< endl;


                for (int i = 0; i < dates.size(); i++) {
                        if (dates.at(i)->getTitle() == userTitle) {
                                dates.at(i)->setPrio(0);
                                index = i;
                        }
                }

		Task* editTask = new Task();
                copy(editTask, dates.at(index));
                editTask->setPrio(0);

                deleteTask(dates.at(index)->getTitle());
                addTask(editTask);
        }

        cout << "Okay. Priority for " << userTitle << " has been changed to " <<  temp << "." << endl;
	cout << getPrintedList(GetDates()) << endl;
//	printVector(priorities); // I want to use this but it gives me a segmentation fault
}

void MainMenu::editDate() {

        cout<<"--------------------------------------------------------------------"<<endl;
        cout<<"|      Please enter the title the task you would like to edit.     |"<<endl;
        cout<<"--------------------------------------------------------------------"<<endl;

        cout << "FIX ME: GET PRINTED LIST" << endl;

        cin.ignore();
        string userTitle;
        getline(cin, userTitle);
        cout<< endl;

	int index = 0;

	string input = "";
	cout<<"---------------------------------------"<<endl;
	cout<<"|           Need a due date?          |"<<endl;
	cout<<"|               y- yes                |"<<endl;
	cout<<"|               n- no (no date)       |"<<endl;
	cout<<"---------------------------------------"<<endl;
	cin>> input;

	while(input!= "y" && input!= "n"){
	cout<<"---------------------------------------"<<endl;
	cout<<"|           Need a due date?          |"<<endl;
	cout<<"|             Enter y- yes            |"<<endl;
	cout<<"|             Enter n- no             |"<<endl;
	cout<<"---------------------------------------"<<endl;
	cin>> input;
	}

	if(input== "y"){
   	cout<<"---------------------------------------"<<endl;
	cout<<"|      Input month in form (xx)       |"<<endl;
    	cout<<"|        Example: July--> 07          |"<<endl;
    	cout<<"---------------------------------------"<<endl;
	int month;
    	cin>> month;
    	cout<< "Month:"<< month << endl;
 //   	newTask->setMonth(month);

    	cout<<"---------------------------------------"<<endl;
    	cout<<"|      Input day in form (xx)          |"<<endl;
    	cout<<"|        Example: day--> 28            |"<<endl;
    	cout<<"---------------------------------------"<<endl;
	int day;
    	cin>> day;
    	cout<< "Day:"<< day << endl;
 //   	newTask->setDay(day);

    	cout<<"---------------------------------------"<<endl;
    	cout<<"|       Input year in form (xxxx)      |"<<endl;
    	cout<<"|      Example: year 2022--> 2022      |"<<endl;
    	cout<<"---------------------------------------"<<endl;
	int year;
    	cin>>year;
    	cout<< "Year:"<<year<<endl;
  //  	newTask->setYear(year);
	
	
        for (int i = 0; i < dates.size(); i++) {
         	if (dates.at(i)->getTitle() == userTitle) {
                	dates.at(i)->setMonth(month);
			dates.at(i)->setDay(day);
			dates.at(i)->setYear(year);
                        index = i;
                }
            }
	}	
 
//FIX ME  
	cout << "Okay. Date for " << userTitle << " has been changed to " <<  dates.at(index) << "." << endl;

	if (input== "n") { 
		cout << "Okay. Date for " << userTitle << " has been changed to no due date" << endl;
    	}

}


