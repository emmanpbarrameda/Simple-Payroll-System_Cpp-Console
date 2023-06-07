#include <iostream>
#include <limits>

//vars
using namespace std;
void restart();


//number input only
double getNumericInput(const std::string& prompt) {
    double input;
    bool validInput = false;

    while (!validInput) {
        std::cout << prompt;

        if (!(std::cin >> input)) {
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            std::cout << "\nInvalid input. Number only. \n";
        } else {
            validInput = true;
        }
    }

    return input;
}



//start
void payrollsystem() {
    cout << "PAYROLL SYSTEM -- DAILY RATE\nby Emman P. Barrameda\n" << endl;

    double hourly = getNumericInput("Enter Hourly Rate: ");

    double hourswork = getNumericInput("Enter Hours of Work: ");

    double dayswork = getNumericInput("Enter Days of Work: ");

    double absences = getNumericInput("Enter Absences: ");

    double tardiness = getNumericInput("Enter Tardiness or 0 if none: ");

    //space
    cout << "" << endl;

    //vars
    double totalgross1 = hourly*hourswork;
    double totalgross2 = totalgross1*dayswork;
    double totalgross3 = absences-tardiness;
    double totalgross_total = totalgross2;

    //total gross
    cout << "TOTAL GROSS: " << totalgross_total << endl;

    //deductions
    cout << "" << endl;
    cout << "Deductions" << endl;
    cout << "----------------" << endl;

    double philhealth = getNumericInput("PhilHealth: ");

    double sss = getNumericInput("SSS: ");

    double tax = getNumericInput("Tax: ");

    double pagibig = getNumericInput("Pag-ibig: ");

    double absences2 = getNumericInput("Absences: ");

    double tardiness2 = getNumericInput("Tardiness: ");

    //vars
    double totaldeduction1 = philhealth+sss+tax+pagibig;
    double totaldeduction2 = totaldeduction1+absences2+tardiness2;
    double totaldeduction_total = totaldeduction1;

    //deduction
    cout << "----------------\n" << endl;
    cout << "Total Deduction: " << totaldeduction_total << endl;

    //total
    double totalsalary_total = totalgross_total-totaldeduction_total;
    cout << "" << endl;
    cout << "TOTAL SALARY: " << totalsalary_total << endl;

    cout << "\n" << endl;

    //restart
    restart();
}

//ask to restart
void restart() {

    cout << "Go Back to Start? [Y/N]" << endl;
    char start;
    cin>> start;

    if(std::tolower(start) == 'y') {
        system("cls");
        payrollsystem();

    } else if (std::tolower(start) == 'n') {
        cout << "Bye!" << endl;
        exit(0);

    } else {
        restart();
    }
}


//start here
int main() {
    payrollsystem();
}



//THIS CONSOLE PROGRAM IS TESTED ON CODEBLOCKS IDE
//Copyright 2021 emmanpbarrameda