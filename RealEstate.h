#ifndef REALESTATE_H
#define REALESTATE_H
#include "Asset.h"
#include<string>
#include<iostream>
using namespace std;
#include<stdlib.h>
#include<fstream>
#include "Utils.h"

class RealEstate : public Asset
{
    public:
        RealEstate();
        RealEstate(string address, double rent);
        double getRent();
        void setRent(double rent);
        string getAddress();
        void setAddress(string adr);
        double simulate();
        void showInfo();
        void edit();
        string serialize();
        void deserialize(ifstream & toDeserialize);
    private:
        double rent;
        string address;
};

#endif // REALESTATE_H
