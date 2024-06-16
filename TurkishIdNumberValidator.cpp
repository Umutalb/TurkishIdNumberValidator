#include <iostream>
#include <string>

using namespace std;

void CheckTcNo(string& tcNo);

int main()
{
    // Turkish ID number verification system.
    // When the sum of the 1st, 3rd, 5th, 7th, and 9th digits of the Turkish ID number is multiplied by 7,
    // and the sum of the 2nd, 4th, 6th, and 8th digits is subtracted, the remainder of the result divided by 10 gives us the 10th digit.
    // The remainder of the sum of the 1st, 2nd, 3rd, 4th, 5th, 6th, 7th, 8th, 9th, and 10th digits divided by 10 gives us the 11th digit.

    setlocale(LC_ALL, "Turkish");
    string tcNo;
    system("cls");
    cout << "Welcome to the Turkish ID verification program \n\n";
    cout << "Please enter the Turkish ID number: ";
    cin >> tcNo;
    cout << endl << endl;

    CheckTcNo(tcNo);

    cout << "\nWould you like to try again? (Y/N): ";
    char retry;
    cin >> retry;
    if (retry == 'Y' || retry == 'y') {
        main();
    }
    else
    {
        cout << "\nExiting the program..." << endl;
    }

    cout << endl;
    return 0;
}

void CheckTcNo(string& tcNo) {
    int digitArray[11];
    bool valid = true;
    int sum = 0;
    int tenthDigit = 0, eleventhDigit = 0;

    string errorMessage = ""; // Created to store error messages.

    if (tcNo.size() != 11) {
        errorMessage += "Invalid Turkish ID number! It must be 11 digits long.\a\n";
        valid = false;
    }

    if (tcNo.size() >= 1 && tcNo.at(0) == '0') {
        errorMessage += "Invalid Turkish ID number! The first digit cannot be 0.\a\n";
        valid = false;
    }

    // Check for errors and display them.
    if (!valid) {
        cout << errorMessage << endl;
        return;
    }

    for (int i = 0; i < 11; i++) {
        if (!isdigit(tcNo.at(i))) {
            cout << "Invalid Turkish ID number! It must contain only digits.\a" << endl << endl;
            return;
        }
        digitArray[i] = tcNo.at(i) - '0'; // Character to digit conversion.
    }

    for (int i = 0; i < 9; i += 2) {
        sum += digitArray[i] * 7;
    }

    for (int i = 1; i < 9; i += 2) {
        sum -= digitArray[i];
    }

    tenthDigit = sum % 10;

    if (tenthDigit != digitArray[9]) {
        cout << "Invalid Turkish ID number! The tenth digit is incorrect.\a" << endl << endl;
        return;
    }

    sum = 0;
    for (int i = 0; i < 10; ++i) {
        sum += digitArray[i];
    }
    eleventhDigit = sum % 10;

    if (eleventhDigit != digitArray[10]) {
        cout << "Invalid Turkish ID number! The eleventh digit is incorrect.\a" << endl << endl;
        return;
    }

    cout << "You have entered a valid Turkish ID number." << endl;
}