#ifndef INDIVIDUALRETIREMENTACCOUNT_H
#define INDIVIDUALRETIREMENTACCOUNT_H
#include<string>
#include<iostream>
using namespace std;
#include<stdlib.h>
#include<fstream>
#include "Utils.h"
#include "Asset.h"


class IndividualRetirementAccount : public Asset
{
    public:
        IndividualRetirementAccount();
        IndividualRetirementAccount(string b, double i, double amount);
        string getInstitution();
        double getInterest();
        void setInstitution(string b);
        void setInterest(double i);
        double simulate();
        void showInfo();
        void edit();
        string serialize();
        void deserialize(ifstream & myfile);
    private:
        string institution;
        double interest;
};

#endif // INDIVIDUALRETIREMENTACCOUNT_H
