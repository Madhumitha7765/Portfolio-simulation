#ifndef UTILS_H
#define UTILS_H
#include<string>
#include <regex>
#include<iostream>
using namespace std;

class Utils
{
public:
    Utils();
    bool is_number(const string& s);
    bool is_date(const string & s);
    bool is_double(const string &s);
private:
};

#endif // UTILS_H
