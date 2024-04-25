/*
 * main.cpp
 *
 *  Date: 04/05/2024
 *  Author: Landon Phillips
 */

#include <iostream>
#include <stdlib.h>
#include <iomanip>
#include <string>
using namespace std;

#include "InvestmentAccount.cpp"
#include "BankingCalculations.cpp"

void dataInterface()
{	
	// Create instance of both classes
	InvestmentAccount userInvestment;	  
	BankingCalculations InvestmentCalculations; 
	// declare vars
	double principal, monthlyDeposit, interest; 
	int years;

	string choice;			 
	bool contRunning = true; 
	// loop for program 
	do
	{

		cout << setfill('*') << setw(34) << '*' << endl;
		cout << "*\t"
			 << "Financial Data Input"
			 << "\t *" << endl;
		cout << setfill('-') << setw(34) << '-' << endl;

		cout << "Initial Investment Amount: $";
		cin >> principal;
		cout << endl;

		cout << "Monthly Deposit: $";
		cin >> monthlyDeposit;
		cout << endl;

		cout << "Annual Interest: %";
		cin >> interest;
		cout << endl;

		cout << "Number of years: ";
		cin >> years;
		cout << endl;

		// setting the data
		userInvestment.setPrincipal(principal);
		userInvestment.setMonthlyDeposit(monthlyDeposit);
		userInvestment.setAnnualInterest(interest);
		userInvestment.setTimePeriod(years);

		// displaying the data
		cout << "Initial Investment Amount: " << setfill(' ') << right << setw(10) << "$" << userInvestment.getPrincipal() << endl;
		cout << "Monthly Deposit: " << setfill(' ') << right << setw(20) << "$" << userInvestment.getMonthlyDeposit() << endl;
		cout << "Annual Interest: " << setfill(' ') << right << setw(20) << " " << userInvestment.getAnnualInterest() << "%" << endl;
		cout << "Number of years: " << setfill(' ') << right << setw(20) << " " << userInvestment.getTimePeriod() << endl;

		cout << endl;

		// use methods to display calculated data
		try
		{
			InvestmentCalculations.InvestmentWithoutDeposits(userInvestment);
		}
		catch (const std::exception &exc)
		{
			cout << exc.what() << endl;
			cout << "error occurred with dataWithoutDeposits" << endl;
			contRunning = false;
		}

		try
		{
			InvestmentCalculations.InvestmentWithDeposits(userInvestment);
		}
		catch (const std::exception &exc)
		{
			cout << exc.what() << endl;
			cout << "error occurred with dataWithDeposits" << endl;
			contRunning = false;
		}

		cout << endl;

		// asking user if they want to continue
		cout << "Continue? y/n" << endl;
		cin >> choice;
		if (choice == "n")
		{
			contRunning = false;
		}
		else
		{
			continue;
		}

	} while (contRunning == true);
}

int main()
{
	try
	{
		dataInterface();
	}
	catch (const std::exception &exc)
	{
		cout << exc.what() << endl;
		cout << "error occurred with dataInterface" << endl;
	}
};
