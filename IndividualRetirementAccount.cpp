#include "IndividualRetirementAccount.h"
#include<iostream>
#include<sstream>
using namespace std;

IndividualRetirementAccount::IndividualRetirementAccount()
{
    //ctor
}

IndividualRetirementAccount::IndividualRetirementAccount(string b, double i, double amount)
{
    this->setName("IRA in "+b);
    this->setValue(amount);
    institution = b;
    interest = i;
}

string IndividualRetirementAccount::getInstitution(){
    return institution;
}

double IndividualRetirementAccount::simulate(){
    this->setValue(this->getValue() + ((interest/365)*this->getValue()));
    return this->getValue();
}
void IndividualRetirementAccount::showInfo(){
    cout<<"Name of asset: "<<this->getName()<<endl;
    cout<<"Name of institution: "<<this->getInstitution()<<endl;
    cout<<"Interest: "<<this->getInterest()<<endl;
    cout<<"Value: $"<<this->getValue()<<endl;
}
void IndividualRetirementAccount::edit(){
    bool exit = false;
    int propertyNumber;
    string newName, newBankName;
    double newInterest=0, newValue=0;

    while(!exit){
        cout<<"1. Name of asset: "<<this->getName()<<endl;
        cout<<"2. Name of institution: "<<this->getInstitution()<<endl;
        cout<<"3. Interest: "<<this->getInterest()<<endl;
        cout<<"4. Value: $"<<this->getValue()<<endl;
        cout<<"5. I am done editing. Go back."<<endl;
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
            cout<<"New institution name: ";
            cin.ignore();
            getline(cin, newBankName);
            institution = newBankName;
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


double IndividualRetirementAccount::getInterest(){
    return interest;
}
void IndividualRetirementAccount::setInstitution(string b){
    institution = b;
}
void IndividualRetirementAccount::setInterest(double i){
    interest = i;
}

string IndividualRetirementAccount::serialize(){
    stringstream s;
    s << "-ira-" <<'\n'<< this->getName() << '\n' << this->getValue() << '\n' << this->getInterest() << '\n' << this->getInstitution()<<'\n';
    return s.str();
}

void IndividualRetirementAccount::deserialize(ifstream & myfile){
    char c;
    string line;
    double value,interest;
    getline (myfile,line);
    this->setName(line);
    myfile >> value;
    while (myfile.get(c) && c != '\n'){

    }

    myfile >> interest;
    while (myfile.get(c) && c != '\n'){
    }
    getline(myfile, line);
    this->setInstitution(line);
    this->setValue(value);
    this->setInterest(interest);
}
