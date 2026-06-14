#include <iostream>
#include <fstream>
#include <iomanip>
#include <string>
#include <cmath>

using namespace std;

int main() {
    string filename;
    cout << "Enter the name of the input file: ";
    cin >> filename;

    ifstream inFile(filename);
    if (!inFile) {
        cout << "Error: Could not open file " << filename << endl;
        return 1;
    }

    string firstName, lastName;
    double baseSalary, commissionPercent, totalSales, expenses;

    inFile >> firstName >> lastName;
    inFile >> baseSalary >> commissionPercent;
    inFile >> totalSales;
    inFile >> expenses;
    inFile.close();

    double commission = totalSales * (commissionPercent / 100.0);
    double total = baseSalary + commission + expenses;
    double displayPercent = floor(commissionPercent * 10) / 10;

    cout << "Payroll data for " << firstName << " " << lastName << endl;
    cout << endl;

    cout << fixed << setprecision(2);
    cout << "Base Salary:"  << setw(11) << baseSalary << endl;

    cout << "Commission:"   << setw(12) << commission;
    cout << " (" << setprecision(1) << displayPercent << "% of ";
    cout << setprecision(2) << totalSales << ")" << endl;

    cout << "Expenses:"     << setw(14) << expenses << endl;
    cout << "               --------" << endl;
    cout << "Total:"        << setw(17) << total << endl;

    return 0;
}
