#include <iostream>
#include <string>

using namespace std;

class BankCard {
private:
    string bankName;
    string holderName;
    int year;
public:

    //Constuctors
    /*
    BankCard(){
        bankName = "";
        holderName = "";
        year = 2000;
    }
    */
    BankCard(string tempBankName = "", string tempHolderName = "", int tempYear = 2000) {
        bankName = tempBankName;
        holderName = tempHolderName;
        year = tempYear;
    }

    //Getters
    string getBank() {
        return bankName;
    }

    string getHolder() {
        return holderName;
    }

    int getYear() {
        return year;
    }

    //Mehtods

    void sendAlert(int currentYear) {
        if (currentYear >= year) {
            cout << "This card is going to expire" << endl;
        }
    }

};

class CreditCard : public BankCard {
private:
    int creditLimit, type;
public:
    CreditCard(int tempCreditLimit, int tempType, string tempBankName, string tempHolderName, int tempYear) : BankCard(tempBankName, tempHolderName, tempYear) {
        creditLimit = tempCreditLimit;
        type = tempType;

    }

    int getLimit() {
        return creditLimit;
    }

    int nOfDoses() {
        if (type == 1) {
            return 60;
        }
        else if (type == 2) {
            return 30;
        }
    }

    void Print() {
        string temp_bank = getBank();
        cout << temp_bank << endl;
        cout << getHolder() << endl;
        cout << getYear() << endl;
        cout << getLimit() << endl;
        cout << nOfDoses() << endl;
    }

};

void checkForExpires(CreditCard* arrayOfCreditCards) {
    for (int i = 0; i < 3; i++) {
        arrayOfCreditCards[i].sendAlert(2022);
    }
}

void sumCreditLimit(CreditCard* arrayOfCreditCards) {
    int sum = 0;
    for (int i = 0; i < 3; i++) {
        sum += arrayOfCreditCards[i].getLimit();
    }
    cout << "Sum of Credit Limit: ";
    cout << sum << endl;
}

int main()
{

    CreditCard a(3000, 1, "Bank 1", "John Smith", 2017);
    CreditCard b(1200, 2, "Bank 1", "John Smith", 2018);
    CreditCard c(4000, 1, "Bank 2", "John Smith", 2020);
    
    a.Print();
    

    CreditCard arrayOfCreditCards[3] = { a, b, c };

    checkForExpires(arrayOfCreditCards);

    sumCreditLimit(arrayOfCreditCards);

    return 0;
}