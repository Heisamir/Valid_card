#include <iostream>
#include <string>
#include <unordered_map>
using namespace std;

unordered_map<string, string> bankMap = {
    {"603799", "meli"},
    {"589210", "sepah"},
    {"627648", "saderat"},
    {"627961", "sanaat"},
    {"603770", "keshavarzi"},
    {"628023", "maskan"},
    {"627760", "post"},
    {"502908", "taavon"},
    {"627412", "eghtesad"},
    {"622106", "parsian"},
    {"502229", "pasargade"},
    {"627488", "karafarin"},
    {"621986", "saman"},
    {"639346", "sina"},
    {"639607", "sarmayeh"},
    {"636214", "tat"},
    {"502806", "shahr"},
    {"502938", "dey"},
    {"603769", "saderat"},
    {"610433", "malat"},
    {"627353", "tejarat"},
    {"589463", "refah"},
    {"627381", "ansar"},
    {"639370", "mehr eghtesad"}
};

bool isValidCardNumber(const string& cardNumber) {
    if (cardNumber.length() != 16)
        return false;
    for (char c : cardNumber) {
        if (!isdigit(c))
            return false;
    }
    return true;
}

string getBankName(const string& cardNumber) {
    string prefix = cardNumber.substr(0, 6);
    if (bankMap.find(prefix) != bankMap.end()) {
        return bankMap[prefix];
    }
    else {
        return "unkhown";
    }
}

void printCardInfo(const string& cardNumber, const string& bankName) {
    cout << "CARD: "
        << cardNumber.substr(0, 4) << "-"
        << cardNumber.substr(4, 4) << "-"
        << cardNumber.substr(8, 4) << "-"
        << cardNumber.substr(12, 4) << endl;
    cout << "BANK: " << bankName << endl;
}

int main() {
    string cardNumber;
    cout << "Enter card number: ";
    cin >> cardNumber;

    if (!isValidCardNumber(cardNumber)) {
        cout << "unvalid card number." << endl;
        return 1;
    }

    string bankName = getBankName(cardNumber);
    printCardInfo(cardNumber, bankName);

    return 0;
}
