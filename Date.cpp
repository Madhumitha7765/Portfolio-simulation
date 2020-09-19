#include "Date.h"


Date::Date()
{
    //default constructor
}

Date::Date(int day, int month, int year)
{
    this->day = day;
    this->month = month;
    this->year = year;
}

int Date::getDay(){
return day;
}
int Date::getMonth(){
return month;
}
int Date::getYear(){
return year;
}
void Date::setDay(int d){
day = d;
}
void Date::setMonth(int m){
month = m;
}
void Date::setYear(int y){
year = y;
}

bool Date::operator>(Date d){
    if(this->getYear() > d.getYear()){
        return true;
    }else if((this->getYear() == d.getYear()) && (this->getMonth() > d.getMonth())){
        return true;
    } else if (((this->getYear() == d.getYear()) && (this->getMonth() == d.getMonth())) && (this->getDay() > d.getDay())){
        return true;
    }else return false;
}

int Date::operator-(Date d){
    return (this->getYear() - d.getYear())*365 + (this->getMonth() - d.getMonth())*30 + (this->getDay() - d.getDay());
}
