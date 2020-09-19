#ifndef ASSET_H
#define ASSET_H
#include <string>
#include<fstream>
#include<iostream>
using namespace std;

class Asset
{
    public:
        string getName();
        void setName(string name);
        double getValue();
        void setValue(double value);
        virtual double simulate()=0;
        virtual void showInfo()=0;
        virtual void edit()=0;
        virtual string serialize()=0;
        virtual void deserialize(ifstream& myfile)=0;
    private:
        string name;
        double value;
};

#endif // ASSET_H
