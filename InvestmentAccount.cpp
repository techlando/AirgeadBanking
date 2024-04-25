/*
 * InvestmentAccount.cpp
 *
 *  Date: 04/05/2024
 *  Author: Landon Phillips
 */

#include <iostream>
using namespace std;

#include "InvestmentAccount.h"

// Mutators
void InvestmentAccount::setPrincipal(double t_principal)
{
	this->m_principal = t_principal;
}

void InvestmentAccount::setMonthlyDeposit(double t_monthlyDeposit)
{
	this->m_monthlyDeposit = t_monthlyDeposit;
}

void InvestmentAccount::setAnnualInterest(double t_annualInterest)
{
	this->m_annualInterest = t_annualInterest;
}

void InvestmentAccount::setTimePeriod(int t_timePeriod)
{
	this->m_timePeriod = t_timePeriod;
}
void InvestmentAccount::setTotalWithoutDeposits(double t_amount)
{
	this->m_totalWithoutDeposits += t_amount;
}

void InvestmentAccount::setTotalWithDeposits(double t_amount)
{
	this->m_totalWithDeposits += t_amount;
}

// methods
double InvestmentAccount::calcInterestWithoutDeposits()
{
	return ((this->m_totalWithoutDeposits) * ((this->m_annualInterest / 100) / 12));
}

double InvestmentAccount::calcInterestWithDeposits()
{
	return ((this->m_totalWithDeposits) * ((this->m_annualInterest / 100) / 12));
}

double InvestmentAccount::getTotalWithDeposits()
{
	return this->m_totalWithDeposits;
}

double InvestmentAccount::getTotalWithoutDeposits()
{
	return this->m_totalWithoutDeposits;
}
