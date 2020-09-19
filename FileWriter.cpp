#include "FileWriter.h"
#include<iostream>
using namespace std;

FileWriter::FileWriter()
{
    //default constructor
}

void FileWriter::saveWalletState(Wallet<Asset> &w){
        ofstream myfile;
        myfile.open("filename");
        vector<Asset *> assets = w.getAssets();
        for(unsigned i=0; i<assets.size(); i++){
             myfile << assets.at(i)->serialize();
        }
        myfile.close();
}

void FileWriter::loadWalletState(Wallet<Asset> &w){
        cout<<"Loading data..."<<endl;
        string line;
        ifstream myfile ("filename");
        if (myfile.is_open())
        {
            while ( getline (myfile,line) )
            {
                if(line=="-deposit-"){
                    BankDeposit* bd = new BankDeposit();
                    bd->deserialize(myfile);
                    w+=bd;
                }else if(line=="-contract-"){
                    Contract* c = new Contract();
                    c->deserialize(myfile);
                    w+=c;
                }else if(line=="-estate-"){
                    RealEstate* re = new RealEstate();
                    re->deserialize(myfile);
                    w+=re;
                }else if(line=="-fundshares-"){
                    InvestmentFundShare* ifs = new InvestmentFundShare();
                    ifs->deserialize(myfile);
                    w+=ifs;
                }else if(line=="-ira-"){
                    IndividualRetirementAccount* ira = new IndividualRetirementAccount();
                    ira->deserialize(myfile);
                    w+=ira;
                }

            }
            myfile.close();
        }

        else cout << "Unable to open file";
}
