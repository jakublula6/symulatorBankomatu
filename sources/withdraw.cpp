﻿#include "withdraw.h"
void Withdraw::setState(int b_500, int b_200, int b_100, int b_50, int b_20, int b_10)
{
    billsAvabile.fifeHundred = b_500;
    billsAvabile.twoHundred = b_200;
    billsAvabile.hundred = b_100;
    billsAvabile.fifty = b_50;
    billsAvabile.twenty = b_20;
    billsAvabile.ten = b_10;
}
bool Withdraw:: isCorrect(int value)
{
    if (value % 10 == 0)
        return true;
    else
        return false;
}
void Withdraw:: handleWithdraw(int value)
{
    if (value > 500 && billsAvabile.fifeHundred - value / 500 >= 0)
    {
        billsWithdrawed.fifeHundred = value / 500;
        value = value - billsWithdrawed.fifeHundred * 500;
        billsAvabile.fifeHundred = billsAvabile.fifeHundred - billsWithdrawed.fifeHundred;
    }
    if (value > 200 && billsAvabile.twoHundred - value / 200 >= 0)
    {
        billsWithdrawed.twoHundred = value / 200;
        value = value - billsWithdrawed.twoHundred * 200;
        billsAvabile.twoHundred = billsAvabile.twoHundred - billsWithdrawed.twoHundred;
    }
    if (value > 100 && billsAvabile.hundred - value / 100 >= 0)
    {
        billsWithdrawed.hundred = value / 100;
        value = value - billsWithdrawed.hundred * 100;
        billsAvabile.hundred = billsAvabile.hundred - billsWithdrawed.hundred;
    }
    if (value > 50 && billsAvabile.fifty - value / 50 >= 0)
    {
        billsWithdrawed.fifty = value / 50;
        value = value - billsWithdrawed.fifty * 50;
        billsAvabile.fifty = billsAvabile.fifty - billsWithdrawed.fifty;
    }
    if (value > 20 && billsAvabile.twenty - value / 20 >= 0)
    {
        billsWithdrawed.twenty = value / 20;
        value = value - billsWithdrawed.twenty * 20;
        billsAvabile.twenty = billsAvabile.twenty - billsWithdrawed.twenty;
    }
    if (value > 10 && billsAvabile.ten - value / 10 >= 0)
    {
        billsWithdrawed.ten = value / 10;
        value = value - billsWithdrawed.ten * 10;
        billsAvabile.ten = billsAvabile.ten - billsWithdrawed.ten;
    }
    // zwrócenie struktury  z liczbą banknotów
    //return
}