#include "Contract.h"
#include<iostream>
#include<sstream>
using namespace std;

Contract::Contract(){
    //default constructor
}

Contract::Contract(string name, double m, double amount){
    this->setName(name);
    this->setValue(amount);
    multiplier = m;
}

double Contract::getMultiplier(){
    return multiplier;
}

void Contract::setMultiplier(double m){
    multiplier = m;
}

double Contract::simulate(){
    if(((((rand() % 10) + 1 ) % 2) == 0) && (this->getValue() - multiplier) > 0){
        this->setValue(this->getValue() - multiplier);
    }else this->setValue(this->getValue() + multiplier);
    return this->getValue();
}
void Contract::showInfo(){
    cout<<"Name of asset: "<<this->getName()<<endl;
    cout<<"Multiplier: "<<this->getMultiplier()<<endl;
    cout<<"Value: $"<<this->getValue()<<endl;
}
void Contract::edit(){
    bool exit = false;
    int propertyNumber;
    string newName;
    double newValue=0, newMultiplier=0;

    while(!exit){
        cout<<"1. Name of Contract: "<<this->getName()<<endl;
        cout<<"2. Multiplier: "<<this->getMultiplier()<<endl;
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
            cout<<"New contract name: ";
            cin.ignore();
            getline(std::cin, newName);
            this->setName(newName);
            system("cls");
            break;
        case 2:
            while(!isValid){
                cout<<msg;
                cout<<"New multiplier: ";
                cin>>inp;
                if(utils.is_double(inp)){
                    isValid=true;
                    newMultiplier = atof( inp.c_str() );
                    msg="";
                }else{
                    msg = "This is not a proper multiplier!\n";
                }
            }
            isValid=false;
            msg="";
            multiplier = newMultiplier;
            this->setMultiplier(newMultiplier);
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

string Contract::serialize(){
    stringstream s;
    s << "-contract-" <<'\n'<< this->getName() << '\n' << this->getValue() << '\n' << this->getMultiplier()<<'\n';
    return s.str();
}

void Contract::deserialize(ifstream & myfile){
    char c;
    string line;
    double value,multiplier;
    getline (myfile,line);
    this->setName(line);
    myfile >> value;
    while (myfile.get(c) && c != '\n'){

    }
    myfile >> multiplier;
    while (myfile.get(c) && c != '\n'){
    }
    this->setValue(value);
    this->setMultiplier(multiplier);
}
