#ifndef FILEWRITER_H
#define FILEWRITER_H

#include <iostream>
using namespace std;
#include <stdlib.h>
#include "Asset.h"
#include "Interface.h"
#include "IndividualRetirementAccount.h"
#include "BankDeposit.h"
#include "Contract.h"
#include "InvestmentFundShare.h"
#include "RealEstate.h"
#include "Wallet.h"


class FileWriter
{
public:
    FileWriter();
    void saveWalletState(Wallet<Asset> &w);
    void loadWalletState(Wallet<Asset> &w);
private:
};

#endif // FILEWRITER_H
