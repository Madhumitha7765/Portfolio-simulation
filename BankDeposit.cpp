#include "BankDeposit.h"
#include<iostream>
#include<sstream>
using namespace std;

BankDeposit::BankDeposit()
{
    //default constructor
}

BankDeposit::BankDeposit(string b, double i, double amount){
    this->setName("Deposit in "+b);
    this->setValue(amount);
    bank = b;
    interest = i;
}
string BankDeposit::getBank(){
    return bank;
}
void BankDeposit::setBank(string b){
    bank = b;
}
double BankDeposit::getInterest(){
    return interest;
}
void BankDeposit::setInterest(double i){
    interest = i;
}
double BankDeposit::simulate(){
    this->setValue(this->getValue() + ((interest/365)*this->getValue()));
    return this->getValue();
}
void BankDeposit::showInfo(){
    cout<<"Name of asset: "<<this->getName()<<endl;
    cout<<"Name of bank: "<<this->getBank()<<endl;
    cout<<"Interest: "<<this->getInterest()<<endl;
    cout<<"Value: $"<<this->getValue()<<endl;
}
void BankDeposit::edit(){
    bool exit = false;
    int propertyNumber;
    string newName, newBankName;
    double newInterest=0, newValue=0;

    while(!exit){
        cout<<"1. Name of asset: "<<this->getName()<<endl;
        cout<<"2. Name of bank: "<<this->getBank()<<endl;
        cout<<"3. Interest: "<<this->getInterest()<<endl;
        cout<<"4. Value: $"<<this->getValue()<<endl;
        cout<<"5. I am done editing. Go back."<<endl;
        Utils utils;
        bool isValid = false;
        string inp, msg="";


        while(!isValid){
                cout<<msg;
                cout<<"What property you want to edit?"<<std::endl;
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
            cout<<"New bank name: ";
            cin.ignore();
            getline(cin, newBankName);
            bank = newBankName;
            system("cls");
            break;
        case 3:
            while(!isValid){
                cout<<msg;
                cout<<"New interest: ";
                cin>>inp;
                if(utils.is_double(inp)){
                    isValid=true;
                    newInterest = atof( inp.c_str() );
                    msg="";
                }else{
                    msg = "This is not a proper interest!\n";
                }
            }
            isValid=false;
            msg="";
            interest = newInterest;
            system("cls");
            break;
        case 4:
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
        case 5:
            exit = true;
            break;
    }

    }

}

string BankDeposit::serialize(){
    stringstream s;
    s << "-deposit-" <<'\n'<< this->getName() << '\n' << this->getValue() << '\n' << this->getBank() << '\n' << this->getInterest()<<'\n';
    return s.str();
}

void BankDeposit::deserialize(ifstream& myfile){
    char c;
    string line;
    double value,interest;
    getline (myfile,line);
    this->setName(line);
    myfile >> value;
    while (myfile.get(c) && c != '\n'){

    }
    getline(myfile, line);
    this->setBank(line);
    myfile >> interest;
    while (myfile.get(c) && c != '\n'){
    }
    this->setValue(value);
    this->setInterest(interest);

}
