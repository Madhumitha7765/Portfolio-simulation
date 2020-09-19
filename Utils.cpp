#include "Utils.h"
#include<iostream>
using namespace std;

Utils::Utils()
{
    //default constructor
}

bool Utils::is_number(const string& s)
{
   return s.find_first_not_of( "0123456789" ) == string::npos;
}

bool Utils::is_date(const string & s){
    regex pattern( "^[[:digit:]]+\\.[[:digit:]]+\\.[[:digit:]]+$" );
    smatch result;
    if(regex_search( s, result, pattern)){
        return true;
    }else return false;
}

bool Utils::is_double(const string &s){
    if(is_number(s)) return true;
    regex pattern( "^[0-9]+[^a-zA-z]+(\\.[0-9]+)?$" );
    smatch result;
    if(regex_search( s, result, pattern)){
        return true;
    }else return false;
}
