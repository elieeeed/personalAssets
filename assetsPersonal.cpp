#include "assets.h"

#include <cmath>
#include <numeric>
#include <vector>
#include <algorithm>

double total_net_worth(const std::vector<std::unique_ptr<PersonalAsset>>& assets) {
    double total = 0;
    for (const auto& asset : assets) {
        total += asset->compute_net_worth();
    }
    return total;
}

std::string trim(const std::string& str) {
    auto start = str.find_first_not_of(" \t\n\r");
    //use trim for end and first
    if (start == std::string::npos) {
        return "";
    }

    auto end = str.find_last_not_of(" \t\n\r");
    return str.substr(start, end - start + 1);
}
