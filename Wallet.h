#ifndef WALLET_H
#define WALLET_H


#include<iostream>
#include<vector>
#include<algorithm>
#include<iostream>
#include <fstream>
#include <string>

using namespace std;

template<class T>
class Wallet{
private:
    vector<T*> assets;
public:
    void operator+=(T* t){
        assets.push_back(t);
    }
    void operator-=(T* t){
        assets.erase(std::remove(assets.begin(), assets.end(), t), assets.end());
    }

    void showAssets(){
        for(unsigned i=0; i<assets.size(); i++){
            cout<<i<<". "<<assets.at(i)->getName()<<", value: $"<<assets.at(i)->getValue()<<endl;
        }
    }

    T* getAsset(int idx){
        return assets.at(idx);
    }

    vector<T*> getAssets(){
        return assets;
    }
};
#endif // WALLET_H
