#include "Interface.h"
#include "Utils.h"
#include <regex>
#include<iostream>
using namespace std;

Interface::Interface()
{
    //default constructor
}

void Interface::showAddMenu(Wallet<Asset> &w){
    int choice;
    cout<<"Choose an asset you want to add from the list below: "<<endl;
    cout <<"1. Bank deposit."<<endl;
    cout <<"2. Contract."<<endl;
    cout <<"3. Individual retirement account." <<endl;
    cout <<"4. Investment fund share."<<endl;
    cout <<"5. Real estate."<<endl;
    Utils utils;
    bool isValid = false;
    string inp, msg="";
    while(!isValid){
        cout<<msg;
        cout <<"Your choice: ";
        cin>>inp;
        try{
        if(utils.is_number(inp)){
            isValid=true;
            choice = atoi( inp.c_str() );
            msg="";
        }else{

                throw inp;
        }
        }
        catch(string inp){            msg = "This is not a number!\n";}
    }
    isValid=false;
    msg="";
    system("cls");
    switch(choice){
    case 1:
        addBankDeposit(w);
        break;
    case 2:
        addContract(w);
        break;
    case 3:
        addIndividualRetirementAccount(w);
        break;
    case 4:
        addInvestmentFundShare(w);
        break;
    case 5:
        addRealEstate(w);
        break;
    }
    FileWriter fw;
    fw.saveWalletState(w);
}


void Interface::addBankDeposit(Wallet<Asset> &w){
    string name;
    double interest,amount;
    cout<<"Provide the name and interest of bank: "<<endl;
    cout<<"Name of bank: ";
    cin.ignore();
    getline (cin,name);
    Utils utils;
    bool isValid = false;
    string inp, msg="";
    while(!isValid){
        cout<<msg;
        cout<<"Interest: ";
        cin>>inp;
        try{
        if(utils.is_double(inp)){
            isValid=true;
            interest = atof( inp.c_str() );
            msg="";
            }else{
                throw inp;
            }
        }catch(string inp){msg = "This is not a proper interest!\n";}
    }
    isValid=false;
    msg="";
    while(!isValid){
        cout<<msg;
        cout<<"Amount of money in USD: ";
        cin>>inp;
        try{
        if(utils.is_double(inp)){
            isValid=true;
            amount = atof( inp.c_str() );
            msg="";
            }else{
                throw inp;
            }
        }catch(string n){msg = "This is not a proper amount!\n";}
    }
    isValid=false;
    msg="";
    system("cls");
    w+=new BankDeposit(name, interest, amount);
    cout<<"Successfully added."<<endl;
}

void Interface::showBalance(Wallet<Asset> &w){
    double sum=0;
    cout<<"Balance: "<<endl;
    vector<Asset*> assets = w.getAssets();
    for(unsigned i=0; i<assets.size(); i++){
        cout<<i<<". "<<assets.at(i)->getName()<<", value: $"<<assets.at(i)->getValue()<<endl;
        sum+=assets.at(i)->getValue();
    }
    cout<<"Total value: $"<<sum<<endl;
    system("pause");
    system("cls");
}
void Interface::showTax(Wallet<Asset> &w){
     double sum=0;
    cout<<"Balance: "<<endl;
    vector<Asset*> assets = w.getAssets();
    for(unsigned i=0; i<assets.size(); i++){
        cout<<i<<". "<<assets.at(i)->getName()<<", value: $"<<assets.at(i)->getValue()<<endl;
        sum+=assets.at(i)->getValue();
    }
    cout<<"Total value: $"<<sum<<endl;
    cout<<"Taxable amount(@18%): $"<<0.18*sum<<endl;
    system("pause");
    system("cls");
}

void Interface::addContract(Wallet<Asset> &w){
    string name;
    double multiplier,amount;
    cout<<"Provide the name and multiplier of contract: "<<endl;
    cout<<"Name of contract: ";
    cin.ignore();
    getline (cin,name);
    Utils utils;
    bool isValid = false;
    string inp, msg="";
    while(!isValid){
        cout<<msg;
        cout<<"Multiplier: ";
        cin>>inp;
    try{
        if(utils.is_double(inp)){
            isValid=true;
            multiplier = atof( inp.c_str() );
            msg="";
        }else{
            throw inp;
        }
    }catch(string inp){msg = "This is not a proper multiplier!\n";}
    }
    isValid=false;
    msg="";
    while(!isValid){
        cout<<msg;
        cout<<"Amount of money in USD: ";
        cin>>inp;
        try{
        if(utils.is_double(inp)){
            isValid=true;
            amount = atof( inp.c_str() );
            msg="";
        }else{
           throw inp;
        }
        }catch(string inp){ msg = "This is not a proper amount!\n";}
    }
    isValid=false;
    msg="";
    system("cls");
    w+=new Contract(name, multiplier, amount);
    cout<<"Successfully added."<<endl;
}

void Interface::addIndividualRetirementAccount(Wallet<Asset> &w){
    string name;
    double interest,amount;
    cout<<"Provide the name and interest of institution: "<<endl;
    cout<<"Name of institution: ";
    cin.ignore();
    getline (std::cin,name);
    Utils utils;
    bool isValid = false;
    string inp, msg="";
    while(!isValid){
        cout<<msg;
        cout<<"Interest: ";
        cin>>inp;

       try
       {
            if(utils.is_double(inp)){
            isValid=true;
            interest = atof( inp.c_str() );
            msg="";
            }else{
                throw inp;
            }
        }catch(string n){msg = "This is not a proper interest!\n";}
    }
    isValid=false;
    msg="";
    while(!isValid){
        cout<<msg;
        cout<<"Amount of money in USD: ";
        cin>>inp;

      try{
            if(utils.is_double(inp))
                {
                isValid=true;
                amount = atof( inp.c_str() );
                msg="";
                }else{
                    throw inp;
                }
            }
        catch(string n){msg = "This is not a proper amount!\n";}
    }
    isValid=false;
    msg="";
    system("cls");
    w+=new IndividualRetirementAccount(name, interest, amount);
    cout<<"Successfully added."<<endl;
    getchar();
}

void Interface::addInvestmentFundShare(Wallet<Asset> &w){
    string name;
    double amount;
    cout<<"Provide the name of investment fund and amount of money: "<<endl;
    cout<<"Name of investment fund: ";
    cin.ignore();
    getline (cin,name);

    Utils utils;
    bool isValid = false;
    string inp, msg="";
    while(!isValid){
        cout<<msg;
        cout<<"Amount of money in USD: ";
        cin>>inp;

        try{
            if(utils.is_double(inp))
                {
                    isValid=true;
                    amount = atof( inp.c_str() );
                    msg="";
                }else{
                   throw inp;
                }
        }
        catch(string inp){ msg = "This is not a proper amount!\n";}
    }
    isValid=false;
    msg="";
    system("cls");
    w+=new InvestmentFundShare(name, amount);
    cout<<"Successfully added."<<endl;
}

void Interface::addRealEstate(Wallet<Asset> &w){
    string address;
    double rent;
    cout<<"Provide the address of real estate and rent: "<<endl;
    cout<<"Address: ";
    cin.ignore();
    getline (cin,address);
    Utils utils;
    bool isValid = false;
    string inp, msg="";
    while(!isValid){
        cout<<msg;
        cout<<"Rent: ";
        cin>>inp;

       try
       {
            if(utils.is_double(inp)){
            isValid=true;
            rent = atof( inp.c_str() );
            msg="";
        }else{
            throw inp;
                }
        }
        catch(string inp){ msg = "This is not a proper rent!\n";}
    }
    isValid=false;
    msg="";
    system("cls");
    w+=new RealEstate(address, rent);
    cout<<"Successfully added."<<endl;
}

//RemoveUtils
void Interface::showRemoveMenu(Wallet<Asset> &w){
    int idx;
    w.showAssets();
    Utils utils;
    bool isValid = false;
    string inp, msg="";
    while(!isValid){
        cout<<msg;
        cout<<"Provide the number of an item you want to remove: ";
        cin>>inp;
        try{
        if(utils.is_number(inp)){
                if(atoi(inp.c_str()) >= 0 && (unsigned)atoi(inp.c_str()) < w.getAssets().size()){
                    isValid=true;
                    idx = atoi( inp.c_str() );
                    msg="";
                }else msg = "This is not a valid index!\n";

        }else{
           throw inp;
        }
    }
    catch(string inp){ msg = "This is not a valid index!\n";}
    }
    isValid=false;
    msg="";
    w-=w.getAsset(idx);
    system("cls");
    cout<<"Successfully removed asset with the number "<<idx<<"."<<endl;
}

void Interface::showViewMenu(Wallet<Asset> &w){
    int idx;
    w.showAssets();
   Utils utils;
    bool isValid = false;
    string inp, msg="";
    while(!isValid){
        cout<<msg;
        cout<<"Provide the number of an item you want to View: ";
        cin>>inp;
        try{
        if(utils.is_number(inp)){
                if(atoi(inp.c_str()) >= 0 && (unsigned)atoi(inp.c_str()) < w.getAssets().size()){
                    isValid=true;
                    idx = atoi( inp.c_str() );
                    msg="";
                }else msg = "This is not a valid index!\n";

        }else{
            throw inp;

        }

    }
    catch(string inp){msg = "This is not a valid index!\n";}
    }
    isValid=false;
    msg="";
    system("cls");
    w.getAsset(idx)->showInfo();
    system("pause");
    system("cls");
}

void Interface::showEditMenu(Wallet<Asset> &w){
    int idx;
    w.showAssets();
    Utils utils;
    bool isValid = false;
    string inp, msg="";
    while(!isValid){
        cout<<msg;
        cout<<"Provide the number of an item you want to edit: ";
        cin>>inp;
        try{
        if(utils.is_number(inp)){
                if(atoi(inp.c_str()) >= 0 && (unsigned)atoi(inp.c_str()) < w.getAssets().size()){
                    isValid=true;
                    idx = atoi( inp.c_str() );
                    msg="";
                }else msg = "This is not a valid index!\n";

        }else{
            throw inp;
           // msg = "This is not a valid index!\n";
        }
        }
        catch(string inp){  msg = "This is not a valid index!\n";}
    }
    isValid=false;
    msg="";
    system("cls");
    w.getAsset(idx)->edit();
    system("cls");
    FileWriter fw;
    fw.saveWalletState(w);
}

void Interface::showMainMenu(){
    cout << "Choose an option from menu below to perform some action: " << endl;
    cout <<"1. Add asset."<<endl;
    cout <<"2. Remove asset."<<endl;
    cout <<"3. View asset." <<endl;
    cout <<"4. Edit asset."<<endl;
    cout <<"5. Show balance."<<endl;
    cout <<"6. Check taxable amount."<<endl;
    cout <<"7. Simulate."<<endl;
    cout <<"8. Exit."<<endl;
}
