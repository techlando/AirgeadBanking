/*
 * InvestmentAccount.h
 *
 *  Date: 04/05/2024
 *  Author: Landon Phillips
 */

#ifndef INVESTMENTACCOUNT_H
#define INVESTMENTACCOUNT_H

class InvestmentAccount
{
public:
   // Mutators
   void setPrincipal(double t_principal);
   void setMonthlyDeposit(double t_monthlyDeposit);
   void setAnnualInterest(double t_annualInterest);
   void setTimePeriod(int t_timePeriod);
   void setTotalWithDeposits(double t_amount);
   void setTotalWithoutDeposits(double t_amount);

   // Accessors
   double getPrincipal()
   {
      return m_principal;
   }
   double getMonthlyDeposit()
   {
      return m_monthlyDeposit;
   }
   double getAnnualInterest()
   {
      return m_annualInterest;
   }
   int getTimePeriod()
   {
      return m_timePeriod;
   }

   // Methods
   double getTotalWithDeposits();
   double getTotalWithoutDeposits();
   double calcInterestWithDeposits();
   double calcInterestWithoutDeposits();

private: // set vars
   double m_principal = 0.0;
   double m_monthlyDeposit = 0.0;
   double m_annualInterest = 0.0;
   int m_timePeriod = 0;
   double m_totalWithDeposits = 0.0;
   double m_totalWithoutDeposits = 0.0;
};

#endif