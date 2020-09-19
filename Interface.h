#ifndef INTERFACE_H
#define INTERFACE_H
#include "Wallet.h"
#include "Asset.h"
#include "FileWriter.h"
#include "Utils.h"
#include <regex>


class Interface
{
public:
    Interface();
    void showAddMenu(Wallet<Asset> &w);
    void addBankDeposit(Wallet<Asset> &w);
    void showBalance(Wallet<Asset> &w);
    void showTax(Wallet<Asset> &w);
    void addContract(Wallet<Asset> &w);
    void addIndividualRetirementAccount(Wallet<Asset> &w);
    void addInvestmentFundShare(Wallet<Asset> &w);
    void addRealEstate(Wallet<Asset> &w);
    void showRemoveMenu(Wallet<Asset> &w);
    void showViewMenu(Wallet<Asset> &w);
    void showEditMenu(Wallet<Asset> &w);
    void showMainMenu();
private:
};

#endif // INTERFACE_H
