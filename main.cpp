#include "assets.h"

#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <memory>

using std::string;
using std::cout;
using std::cin;


int main() {
    std::vector<std::unique_ptr<PersonalAsset>> assets;

    while (true) {
        cout << "Enter asset type (Automobile, Jewelry, RealEstate, Stock, Bond, SavingsAccount, CheckingAccount, LoanAccount): ";
        string assetType;
        
        getline(cin, assetType);
        assetType.erase(std::remove_if(assetType.begin(), assetType.end(), ::isspace), assetType.end());

        for (char& c : assetType) {
			if(std::isalpha(c))
			    c = std::tolower(c);
		}

        assetType = trim(assetType);
        
        if (assetType == "automobile") {
            double value;
            string make;
            string model;
            int year;
            cout << "Enter your price - make - model - year respectively: ";
            cin >> value >> make >> model >> year;
            assets.push_back(std::make_unique<Automobile>(value,make,model,year));
        } else if (assetType == "jewelry") {
            double value;
            string material;
            string gemstone;
            cout << "Enter your price - material - gemstone respectively: ";
            cin >> value >> material >> gemstone;
            assets.push_back(std::make_unique<Jewelry>(value,material,gemstone));
        } else if (assetType == "realestate") {
            double value;
            double meterage;
            string place;
            cout << "Enter your price - meterage - place respectively : ";
            cin >> value >> meterage >> place;
            assets.push_back(std::make_unique<RealEstate>(value,meterage,place));
        } else if (assetType == "stock") {
            double value;
            cout << "Enter your price: ";
            cin >> value;
            assets.push_back(std::make_unique<Stock>(value));
        } else if (assetType == "bond") {
            double value;
            cout << "Enter your price: ";
            cin >> value;
            assets.push_back(std::make_unique<Bond>(value));
        } else if (assetType == "savingsaccount") {
            double value;
            cout << "Enter your price: ";
            cin >> value;
            assets.push_back(std::make_unique<SavingsAccount>(value));
        } else if (assetType == "checkingaccount") {
            double value;
            cout << "Enter your price: ";
            cin >> value;
            assets.push_back(std::make_unique<CheckingAccount>(value));
        } else if (assetType == "loanaccount") {
            double value;
            cout << "Enter your price: ";
            cin >> value;
            assets.push_back(std::make_unique<LoanAccount>(value));
        } else {
            cout << "Invalid asset type." << std::endl;
            break;
        }
        cin.ignore(); //Clear beacuse of buffer to remove Enter key after our text
    }

    double net_worth = total_net_worth(assets);

    cout << "Total Net Worth: $" << net_worth << std::endl;

    return 0;
}
