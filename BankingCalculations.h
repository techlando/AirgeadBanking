/*
 * BankingCalculations.h
 *
 *  Date: 04/05/2024
 *  Author: Landon Phillips
 */

#ifndef BANKINGCALCULATIONS_H
#define BANKINGCALCULATIONS_H

#include "InvestmentAccount.h"

class BankingCalculations
{
public:
    // helper
    void InvestmentWithoutDeposits(InvestmentAccount t_userInvestment);
    void InvestmentWithDeposits(InvestmentAccount t_userInvestment);
};

#endif
