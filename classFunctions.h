#include <iostream>
#include <string>
using namespace std;

class PlayerMoney
{
    private:
        int startingAmount;

    public:
        int startingBalance;
        int currentBalance;
        PlayerMoney();
        PlayerMoney(int);
        void moneyTracker(string, string, int);
};

/*============================================================================*/

class WheelOfFortune
{
    PlayerMoney player;
    public:
        WheelOfFortune();
        int wheelMovement();
        void secondMenu(int);
        int moneyWonLose();
        
};

/*============================================================================*/

class Roulette
{
    PlayerMoney player;
    private:
        string playerChoice;
    public:
        Roulette();
        void allChoices();
};

/*============================================================================*/

class DealNoDeal
{
    PlayerMoney player;
    private:
        int arrayBriefcases[3][3];
        int max;
        int min;
        int one   = 1;
        int two   = 2;
        int three = 3;
        int four  = 4;
        int five  = 5;
        int six   = 6;
        int seven = 7;
        int eight = 8;
        int nine  = 9;
        int briefcaseValue = 0;
    public:
        DealNoDeal();
        void setBriefcaseValue();
        int playerChoice(int);
        void display();
        void userBriefcaseChoice(int);
};

/*============================================================================*/

