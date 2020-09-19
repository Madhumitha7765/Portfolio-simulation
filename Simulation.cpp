#include "Simulation.h"
#include<iostream>
using namespace std;

Simulation::Simulation()
{
    //default constructor
}

void Simulation::beginSimulation(Wallet<Asset> wallet){
    vector<double> valuesBeforeSimulation;
    double sum=0;
    vector<Asset*> assets = wallet.getAssets();

    system("cls");
    cout<<"Simulation: "<<endl;
    cout<<"Your balance today: "<<endl;
    for(unsigned i=0; i<assets.size(); i++){
        cout<<i<<". "<<assets.at(i)->getName()<<", value: $"<<assets.at(i)->getValue()<<endl;
        valuesBeforeSimulation.push_back(assets.at(i)->getValue());
        sum+=assets.at(i)->getValue();
    }

    time_t t = time(0);
    struct tm * now = localtime( & t );
    int today = now->tm_mday;
    int thisMonth = now->tm_mon + 1;
    int thisYear = now->tm_year + 1900;

    Date currentDate(today, thisMonth, thisYear);
    bool dateValid = false;
    int endDay,endMonth,endYear;
    string inp;
    Date futureDate;
    cout<<"Today is "<<today<<"."<<thisMonth<< "."<< thisYear<<" and your savings are: $"<<sum<<endl;
    while(!dateValid){
        cout<<"Provide the end date of the simulation below in the following format: DAY.MONTH.YEAR "<<endl;
        cout<<"End date: ";
        cin>>inp;

        stringstream s;
        s << inp;
        Utils utils;
        if(utils.is_date(inp)){
            sscanf(inp.c_str(), "%d.%d.%d", &endDay, &endMonth, &endYear);
            futureDate.setDay(endDay);
            futureDate.setMonth(endMonth);
            futureDate.setYear(endYear);
            if((futureDate > currentDate) && ((endDay < 32 && endDay > 0) && (endMonth < 13 && endMonth > 0))){
                dateValid = true;
            }else{
                cout<<"Given date is not valid."<<endl;
            }
        }else cout<<"Wrong format!"<<endl;
    }



    cout<<"Performing simulation... Please wait."<<endl;
    unsigned differenceInDays = futureDate - currentDate;
    cout<<"Difference in days: "<<differenceInDays<<endl;
    for(unsigned j=0; j<differenceInDays; j++){
        for(unsigned i=0; i<assets.size(); i++){
            assets.at(i)->simulate();
        }
    }
    sum=0;
    cout<<"According to the simulation your balance on "<<futureDate.getDay()<<"."<<futureDate.getMonth()<<"."<<futureDate.getYear()<<" will be: "<<endl;
    for(unsigned i=0; i<assets.size(); i++){
        cout<<i<<". "<<assets.at(i)->getName()<<", value: $"<<assets.at(i)->getValue()<<endl;
        sum+=assets.at(i)->getValue();
        assets.at(i)->setValue(valuesBeforeSimulation.at(i));
    }
    cout<<"And the total: $"<<sum<<endl;

    system("pause");
    system("cls");
}
