#ifndef DATE_H
#define DATE_H
class Date {
    int day;
    int month;
    int year;
    bool noIssue= true;
    public:
    Date();
    Date(int m, int d, int y);
    void monthChecker(int m);
    void dayChecker(int day, int year);
    /*getter and setter*/
    int getDay() const;
    int getMonth() const;
    int getYear() const;
    void setDay(int);
    void setMonth(int);
    void setYear(int);
    bool isLeap(int y) const;
    unsigned daysPerMonth(int m, int y) const;
};
#endif 
