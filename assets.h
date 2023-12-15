#include <string>
#include <vector>
#include <memory>

class PersonalAsset {
public:
    virtual double compute_net_worth() const = 0;

protected:
    explicit PersonalAsset(double value) : value(value) {}
    double value;

};


class Automobile : public PersonalAsset {
public:
    explicit Automobile(double value, const std::string& make, const std::string& model, int year)
        : PersonalAsset(value), make(make), model(model), year(year){}

    double compute_net_worth() const override {
        return value;
    }

private:
    std::string make;
    std::string model;
    int year;
};

class Jewelry : public PersonalAsset {
public:
    explicit Jewelry(double value, const std::string& material, const std::string& gemstone)
        : PersonalAsset(value), material(material), gemstone(gemstone) {}

    double compute_net_worth() const override {
        return value;
    }

private:
    std::string material;
    std::string gemstone;    
};

class RealEstate : public PersonalAsset {
public:
    explicit RealEstate(double value, const double meterage, const std::string& place) 
        : PersonalAsset(value), meterage(meterage), place(place) {}

    double compute_net_worth() const override {
        return value;
    }

private:
    double meterage;
    std::string place;
};

class Security : public PersonalAsset {
public:
    virtual double compute_net_worth() const override = 0;
    
protected:
    explicit Security(double value) : PersonalAsset(value) {}
};

class Stock : public Security {
public:
    explicit Stock(double value) : Security(value) {}

    double compute_net_worth() const override {
        return value;
    }
};

class Bond : public Security {
public:
    explicit Bond(double value) : Security(value) {}

    double compute_net_worth() const override {
        return value;
    }
};

class BankAccount : public PersonalAsset {
public:
    virtual double compute_net_worth() const override = 0;
    
protected:
    explicit BankAccount(double value) : PersonalAsset(value) {}
};

class SavingsAccount : public BankAccount {
public:
    explicit SavingsAccount(double value) : BankAccount(value) {}

    double compute_net_worth() const override {
        return value;
    }
};

class CheckingAccount : public BankAccount {
public:
    explicit CheckingAccount(double value) : BankAccount(value) {}

    double compute_net_worth() const override {
        return value;
    }
};

class LoanAccount : public BankAccount {
public:
    explicit LoanAccount(double value) : BankAccount(value) {}

    double compute_net_worth() const override {
        return -value;
    }
};

double total_net_worth(const std::vector<std::unique_ptr<PersonalAsset>>& assets);

std::string trim(const std::string& str);
