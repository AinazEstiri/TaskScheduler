#ifndef __task__hpp__
#define __task__hpp__

#include <iostream>
#include <string>
#include "date.cpp"

using namespace std;

class Task {
  private: 
    string title;
    string desc;
    int prio;
    string tag;
    Date due_date;
  public:
    Task(){ title="Default", desc= "", prio=0, tag="N/A";}
    Task(string title, string desc, int prio, string tag):title(title), desc(desc), prio(prio), tag(tag){};
    void setTitle(string newTitle) {title = newTitle;}
    string getTitle() {return title;}
    void setPrio(int newPrio) {prio = newPrio;}
    int getPrio() {return prio;}
    void setTag(string newTag) {tag = newTag;}
    string getTag() {return tag;}
    void setDesc(string newDesc) {desc = newDesc;}
    string getDesc() {return desc;}

    void setDay(int day) {due_date.setDay(day);};
    void setMonth(int month){due_date.setMonth(month);}; 
    void setYear(int year) {due_date.setYear(year);};
	
    int getDay() {return due_date.getDay();};
    int getMonth(){return due_date.getMonth();};
    int getYear() {return due_date.getYear();};


};

#endif //__task__hpp
