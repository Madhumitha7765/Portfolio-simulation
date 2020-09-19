#ifndef CONTRACT_H
#define CONTRACT_H
#include "Date.h"
#include "Asset.h"
#include<iostream>
using namespace std;
#include<stdlib.h>
#include<fstream>
#include "Utils.h"

class Contract : public Asset
{
    public:
        Contract();
        Contract(string name, double m, double amount);
        double getMultiplier();
        void setMultiplier(double);
        double simulate();
        void showInfo();
        void edit();
        string serialize();
        void deserialize(ifstream & myfile);
    private:
        double multiplier;

};

#endif // CONTRACT_H
