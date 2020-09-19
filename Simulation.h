#ifndef SIMULATION_H
#define SIMULATION_H
#include "Wallet.h"
#include "Asset.h"
#include <stdlib.h>
#include <ctime>
#include<stdio.h>
#include "Date.h"
#include "Utils.h"
#include<sstream>

class Simulation
{
    public:
        Simulation();
        void beginSimulation(Wallet<Asset> wallet);
    private:
};

#endif // SIMULATION_H
