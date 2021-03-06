#include "account.h"
Account:: Account()
{

}
Account:: Account(String p, int max, int balance)
{
	pin = p;
	maxWithdraw = max;
	accountBalance = balance;
}
void Account::setAccount(String p, int max, int balance)
{
	pin = p;
	maxWithdraw = max;
	accountBalance = balance;
}
int Account::checkBalance()
{
    return accountBalance;
}
void Account::shouldBlock()
{
    if (pinAtempts >= 3)
    {
        isBlocked = true;
    }    
}
bool Account::isPinCorrect(String enteredPin)
{
    if (enteredPin == pin && !isBlocked)
    {
        return true;
    }  
    else
    {
        pinAtempts = pinAtempts + 1;
        shouldBlock();
        return false;
    }
}
bool Account::isLowerThanLimit(int request)
{
    if (request <= (maxWithdraw - withdrawed))
    {
        return true;
    }   
    else
    {
        return false;
    }    
}
bool Account::isLowerThanBalance(int request)
{
    if (request <= accountBalance)
    {
        return true;
    }  
    else
    {
        return false;
    }  
}
void Account::handleWithdraw(int request)
{
    withdrawed = withdrawed + request;
    accountBalance = accountBalance - request;
}
void Account::resetLimit()
{
    //zresetowanie limitów na karcie o północy lub po 24h
}
bool Account::changePin(String newPin)
{
	if (newPin != pin && newPin.Length()>0)
	{
        pin = newPin;
        return true;
    }
    else
    {
        return false;
    }   
}