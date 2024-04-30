#include <iostream>
#include <string>
using namespace std;

bool isNumberString(const string& s) {
    for (char c : s) {
        if (!isdigit(c))
            return false;
    }
    return true;
}

bool isValidLuhn(const string& cardNo) {
    int nDigits = cardNo.length();
    int nSum = 0;
    bool isSecond = false;

    for (int i = nDigits - 1; i >= 0; i--) {
        int digit = cardNo[i] - '0';

        if (isSecond)
            digit *= 2;

        // If doubled digit is greater than 9, add its digits
        nSum += (digit > 9) ? (digit - 9) : digit;

        isSecond = !isSecond;
    }

    return (nSum % 10 == 0);
}

int main() {
    string cardNo;
    cout << "Enter a credit card number: ";
    cin >> cardNo;

    if (!isNumberString(cardNo)) {
        cout << "Invalid input. Please enter numeric digits only." << endl;
        return 1;
    }

    if (isValidLuhn(cardNo))
        cout << "Valid credit card number." << endl;
    else
        cout << "Invalid credit card number." << endl;

    return 0;
}