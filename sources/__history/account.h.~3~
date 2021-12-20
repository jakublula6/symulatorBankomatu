#include <iostream>

class Account
{
    private:
        String pin;
        int pinAtempts;
        int maxWithdraw;
        int withdrawed = 0;;
        int accountBalance;
        void shouldBlock();
    public:
        bool isBlocked = false;
        int checkBalance();
        void setAccount(String p, int max, int balance);
        bool isPinCorrect (String enteredPin);
        bool isLowerThanLimit(int request);
        bool isLowerThanBalance(int request);
        void handleWithdraw(int request);
        void resetLimit();
        bool changePin(String newPin);

};