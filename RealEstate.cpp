#include "RealEstate.h"
#include<iostream>
#include<sstream>
using namespace std;

RealEstate::RealEstate()
{
    //default construcctor
}

RealEstate::RealEstate(string addr, double r){
    this->setName("Real estate located at "+ addr);
    this->setValue(0);
    address = addr;
    rent = r;
}
double RealEstate::getRent(){
    return rent;
}
void RealEstate::setRent(double r){
    rent = r;
}
string RealEstate::getAddress(){
return address;
}
void RealEstate::setAddress(string adr){
address = adr;
}
double RealEstate::simulate(){
    this->setValue(this->getValue() + this->getRent()/30);
    return this->getValue();
}
void RealEstate::showInfo(){
    cout<<"Name of asset: "<<this->getName()<<endl;
    cout<<"Address: "<<this->getAddress()<<endl;
    cout<<"Rent: "<<this->getRent()<<endl;
    cout<<"Value: $"<<this->getValue()<<endl;
}
void RealEstate::edit(){
    bool exit = false;
    int propertyNumber;
    string newName, newBankName;
    double newRent=0, newValue=0;

    while(!exit){
        cout<<"1. Name of asset: "<<this->getName()<<endl;
        cout<<"2. Address: "<<this->getAddress()<<endl;
        cout<<"3. Rent: $"<<this->getRent()<<endl;
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
            cout<<"New address: ";
            cin.ignore();
            getline(cin, newBankName);
            address = newBankName;
            system("cls");
            break;
        case 3:

            while(!isValid){
                cout<<msg;
                cout<<"New rent: ";
                cin>>inp;
                if(utils.is_double(inp)){
                    isValid=true;
                    newRent = atof( inp.c_str() );
                    msg="";
                }else{
                    msg = "This is not a proper rent!\n";
                }
            }
            isValid=false;
            msg="";
            rent = newRent;
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

string RealEstate::serialize(){
    stringstream s;
    s << "-estate-" <<'\n'<< this->getName() << '\n' << this->getValue() << '\n' << this->getRent() << '\n' << this->getAddress()<<'\n';
    return s.str();
}

void RealEstate::deserialize(ifstream & myfile){
    char c;
    string line;
    double value,rent;
    getline (myfile,line);
    this->setName(line);
    myfile >> value;
    while (myfile.get(c) && c != '\n'){

    }

    myfile >> rent;
    while (myfile.get(c) && c != '\n'){
    }
    getline(myfile, line);
    this->setAddress(line);
    this->setValue(value);
    this->setRent(rent);
}

