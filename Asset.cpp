#include "Asset.h"
#include<iostream>
using namespace std;

string Asset::getName(){
    return name;
}
void Asset::setName(string n){
    name = n;
}
double Asset::getValue(){
    return value;
}
void Asset::setValue(double p){
    value = p;
}
