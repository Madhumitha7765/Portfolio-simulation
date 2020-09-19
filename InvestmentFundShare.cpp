#include "InvestmentFundShare.h"
#include<iostream>
#include<sstream>
using namespace std;

InvestmentFundShare::InvestmentFundShare(){
    //default constructor
}

InvestmentFundShare::InvestmentFundShare(string n, double amount){
    this->setValue(amount);
    this->setName("Investment fund shares in "+n);
    fundName = n;
}

string InvestmentFundShare::getFundName(){
return fundName;
}
void InvestmentFundShare::setFundName(string n){
fundName = n;
}
double InvestmentFundShare::simulate(){
    if(((((rand() % 10) + 1 ) % 2) == 0) && (this->getValue()/20) != 0){

        this->setValue(this->getValue() - this->getValue()/20);

    }else this->setValue(this->getValue() + this->getValue()/20);
    return this->getValue();
}
void InvestmentFundShare::showInfo(){
    cout<<"Name of asset: "<<this->getName()<<endl;
    cout<<"Name of fund: "<<this->getFundName()<<endl;
    cout<<"Value: $"<<this->getValue()<<endl;
}
void InvestmentFundShare::edit(){
    bool exit = false;
    int propertyNumber;
    string newName, newBankName;
    double newValue=0;

    while(!exit){
        cout<<"1. Name of asset: "<<this->getName()<<endl;
        cout<<"2. Name of fund: "<<this->getFundName()<<endl;
        cout<<"3. Value: $"<<this->getValue()<<endl;
        cout<<"4. I am done editing. Go back."<<endl;
        Utils utils;
        bool isValid = false;
        string inp, msg="";
        while(!isValid){
                cout<<msg;
                cout<<"What property you want to edit?"<<endl;
                cin>>inp;
                if(utils.is_number(inp)){
                    isValid=true;
                    propertyNumber = atof( inp.c_str() );
                    msg="";
                }else{
                    msg = "This is not a valid number!\n";
                }
        }
        isValid = false;
        msg = "";
        switch(propertyNumber){
        case 1:
            cout<<"New asset name: ";
            cin.ignore();
            getline(cin, newName);
            this->setName(newName);
            system("cls");
            break;
        case 2:
            cout<<"New fund name: ";
            cin.ignore();
            getline(cin, newBankName);
            fundName = newBankName;
            system("cls");
            break;
        case 3:
            while(!isValid){
                cout<<msg;
                cout<<"New value: ";
                cin>>inp;
                if(utils.is_double(inp)){
                    isValid=true;
                    newValue = atof( inp.c_str() );
                    msg="";
                }else{
                    msg = "This is not a proper value!\n";
                }
            }
            isValid=false;
            msg="";
            this->setValue(newValue);
            system("cls");
            break;
        case 4:
            exit = true;
            break;
    }

    }

}

string InvestmentFundShare::serialize(){
    stringstream s;
    s << "-fundshares-" <<'\n'<< this->getName() << '\n' << this->getValue() << '\n' << this->getFundName()<<'\n';
    return s.str();
}

void InvestmentFundShare::deserialize(ifstream & myfile){
    char c;
    string line;
    double value;
    getline (myfile,line);
    this->setName(line);
    myfile >> value;
    while (myfile.get(c) && c != '\n'){

    }
    getline(myfile, line);
    this->setFundName(line);
    this->setValue(value);
}
