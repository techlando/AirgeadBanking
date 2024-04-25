/*
 * BankingCalculations.cpp
 *
 *  Date: 04/05/2024
 *  Author: Landon Phillips
 */

#include <iostream>
#include <stdlib.h>
#include <iomanip>
#include <string>
using namespace std;

#include "BankingCalculations.h"

void BankingCalculations::InvestmentWithoutDeposits(InvestmentAccount t_userInvestment)
{
    // set local vars with input data
    double initialInvestment = t_userInvestment.getPrincipal();
    int years = t_userInvestment.getTimePeriod();

    // menu alignment
    int screenWidth = 80;
    string balanceMsg = "Balance & Interest Without Additional Monthly Deposits";
    int centerScreen = balanceMsg.length() / 2;
    int halfWidth = screenWidth / 2;
    int sizeToCenter = halfWidth + centerScreen;

    cout << endl;

    // header for menu
    cout << setfill(' ') << setw(sizeToCenter) << balanceMsg << setfill(' ') << setw(sizeToCenter) << endl;
    cout << setfill('=') << setw(80) << '=' << endl;
    cout << setfill(' ') << left << setw(26) << "Year"
         << "Year End Earned Interest" << right << setw(30) << "Year End Balance" << endl;
    cout << setfill('-') << setw(80) << '-' << endl;

    // adds the initial amount to the total
    t_userInvestment.setTotalWithoutDeposits(initialInvestment);
    double interestYTD = 0;

    unsigned int yearCount, monthCount;

    // runs calculations
    for (yearCount = 1; yearCount <= years; yearCount++)
    {
        for (monthCount = 1; monthCount <= 12; monthCount++)
        {
            interestYTD += t_userInvestment.calcInterestWithoutDeposits();
        }
        t_userInvestment.setTotalWithoutDeposits(interestYTD); // adds total interest from the year to main total
        cout << setfill(' ') << left << setw(30) << yearCount;
        cout << "$" << fixed << setprecision(2) << interestYTD;
        cout << right << setw(35) << "$" << fixed << setprecision(2) << t_userInvestment.getTotalWithoutDeposits() << endl;

        interestYTD = 0; // reset
    }
}

void BankingCalculations::InvestmentWithDeposits(InvestmentAccount t_userInvestment)
{
    // set local vars with input data
    double initialInvestment = t_userInvestment.getPrincipal();
    double monthlyDeposit = t_userInvestment.getMonthlyDeposit();
    int years = t_userInvestment.getTimePeriod();

    string balanceMsg = "Balance & Interest With Additional Monthly Deposits";
    int screenWidth = 80;

    // menu alignment
    int centerScreen = balanceMsg.length() / 2;
    int halfWidth = screenWidth / 2;
    int sizeToCenter = halfWidth + centerScreen;

    cout << endl;

    // header for menu
    cout << setfill(' ') << setw(sizeToCenter) << balanceMsg << setfill(' ') << setw(sizeToCenter) << endl;
    cout << setfill('=') << setw(80) << '=' << endl;
    cout << setfill(' ') << left << setw(26) << "Year"
         << "Year End Earned Interest" << right << setw(30) << "Year End Balance" << endl;
    cout << setfill('-') << setw(80) << '-' << endl;

    // adds the initial amount to the total
    t_userInvestment.setTotalWithDeposits(initialInvestment);

    // reset interest totals
    double interestYTD = 0;

    unsigned int yearCount, monthCount;

    // runs the calculations
    for (yearCount = 1; yearCount <= years; yearCount++)
    {
        for (monthCount = 1; monthCount <= 12; monthCount++)
        {
            t_userInvestment.setTotalWithDeposits(monthlyDeposit);
            double interest = t_userInvestment.calcInterestWithDeposits();
            t_userInvestment.setTotalWithDeposits(interest);
            interestYTD += interest;
        }
        // adds total interest from the year to main total
        cout << setfill(' ') << left << setw(26) << yearCount;
        cout << "$" << fixed << setw(37) << setprecision(2) << interestYTD;
        cout << left << "$" << fixed << setprecision(2) << t_userInvestment.getTotalWithDeposits() << endl;

        interestYTD = 0; // reset
    }
}