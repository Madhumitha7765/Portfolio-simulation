#ifndef INVESTMENTFUNDSHARE_H
#define INVESTMENTFUNDSHARE_H
#include<string>
#include<stdlib.h>
#include<fstream>
#include<iostream>
using namespace std;
#include "Asset.h"
#include "Utils.h"

class InvestmentFundShare : public Asset
{
    public:
        InvestmentFundShare();
        InvestmentFundShare(string name, double amount);
        string getFundName();
        void setFundName(string name);
        double simulate();
        void showInfo();
        void edit();
        string serialize();
        void deserialize(ifstream & myfile);
    private:
        string fundName;
};

#endif // INVESTMENTFUNDSHARE_H
