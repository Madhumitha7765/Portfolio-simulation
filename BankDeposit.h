#ifndef BANKDEPOSIT_H
#define BANKDEPOSIT_H
#include "Asset.h"
#include<string>
#include<stdlib.h>
#include<fstream>
#include "Utils.h"
#include<iostream>
using namespace std;

class BankDeposit : public Asset
{
    public:
        BankDeposit();
        BankDeposit(string b, double i, double amount);
        string getBank();
        void setBank(string b);
        double getInterest();
        void setInterest(double i);
        double simulate();
        void showInfo();
        void edit();
        string serialize();
        void deserialize(ifstream& myfile);
    private:
        double interest;
        string bank;
};

#endif // BANKDEPOSIT_H
