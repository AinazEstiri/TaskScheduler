#ifndef DATE_C
#define  DATE_C

#include <iostream>
#include <string>
#include <cctype>
#include "date.h"
using namespace std;



Date::Date(){
    day=-01;
    month= 01;
    year= 2022;
}
Date::Date(int m, int d, int y){
    month = m;
    day = d;
    year = y;
    /*check month is valid:*/
    monthChecker(month);
    /*check day is valid given month:*/
    dayChecker(day, year);
    
    /*output if there is issue:*/
    if(!noIssue){
        cout<<"Invalid date values: Date corrected to "<<month<<"/"<<day<<"/"<<year<<". To change the due date, edit this Task."<<endl;
    }
}
int Date::getDay() const{
    return this->day;
}
int Date::getMonth() const{
    return this->month;
}
int Date::getYear() const{
    return this->year;
}
void Date::setDay(int d){
    this->day=d;

}
void Date::setMonth(int m){
    this->month=m;
}
void Date::setYear(int y){
    this->year=y;
}

bool Date::isLeap(int y) const{
    if(y%4==0){
        if(y%100==0){
            if(y% 400==0){
                return true;
            }
            return false;
        }
        else{
            return true;
        }
    }
    else{
        return false;
    }
}
unsigned Date::daysPerMonth(int m, int y) const{
    if(month == 2){
        if(isLeap(y)){
            return 29;
        }
        else{
            return 28;
        }
    }

    else if(month == 1 || month == 3 || month == 5 || month == 7 || month == 8 ||month == 10 || month==12){
        return 31;
    }
    else{
        return 30;
    }
}


void Date::monthChecker(int m){
    if(month<1 || month>12){
           if(month > 12){
               month = 12;

               noIssue=false;
           }
           else if(month<1){
               month=01;

               noIssue=false;
           }
       }
}
void Date::dayChecker(int d,  int y){
    if(d>daysPerMonth(month,year)){
        day=daysPerMonth(month,year);
      
        noIssue=false;
    }
    else if(d<1){
        day=01;
    
        noIssue=false;
    }
}

#endif
