#include <iostream>
#include <string>
#include <fstream>
#include <stdlib.h> //for random
#include "classFunctions.h"
using namespace std;

/*PLAYER MONEY.CPP*/
/*=======================================================================================================================================================================*/

PlayerMoney::PlayerMoney()
{
    
    currentBalance = 10000;
}
PlayerMoney::PlayerMoney(int currBalance)
{
    currentBalance = currBalance;
}

void PlayerMoney::moneyTracker(string gamePlayed, string winLoss, int amtWonLost)
{
    //ifstream is in
    ifstream moneyFile;
    moneyFile.open("bankAccount.txt");

    moneyFile.close();
}   
/*int main()
{
    PlayerMoney object;
    object.subtractMoney(10);
    return 0;
}*/


/*WHEEL OF FORTUNE.CPP*/
/*=======================================================================================================================================================================*/
WheelOfFortune::WheelOfFortune()
{
    int dollarAmount;
    PlayerMoney pMoney;
}
int WheelOfFortune::wheelMovement()
{
    int arr[2][8];
   arr[1][0] = 1;
   arr[1][1] = 2;
   arr[1][2] = 3;
   arr[1][3] = -10;
   arr[1][4] = 3;
   arr[1][5] = 2;
   arr[1][6] = 1;
   arr[1][7] = -2;
    int min = 7;
    int max = 32; 
    int i = 1;
    int l = 0;
    for(int m = 0; m < 2; m++)
    {
       
        int random;
        while(i < 10 + l)
        {
            random = rand() % max;
            i++;
        }
        l++;
        
        //cout << " random " << random << endl;
        int spinStop = random % 8; //because each spin goes through 8 times
        int temp = 0;
        // for(int i=spinStop-1; i < 32; i++)
        // {
            for(int j=random; j>=0; j--)
            {
                if(j==7)
                {
                    temp = arr[1][0];
                    arr[1][0] = arr[1][j];
                }
                if(j == 0)
                {
                    arr[1][1] = temp;
                }
                else
                {
                   arr[1][j+1] = arr[1][j]; 
                }
            }
        // }
        for(int k = 0; k<8; k++)
        {
            cout << arr[1][k] << endl;
        } 
    }
    // sorts array in a way that makes it like a spin- first element becomes second element
    // second element moves to third element and last element goes to first element etc...
    // prints out the array each time so user can see how it "spins"
    // randomizer controls how long it should spin
}

void WheelOfFortune::secondMenu(int userDecision)
{
    cout<<"1. Spin"<<endl;
    cout<<"2. Look at Bank Account"<<endl;
    if(userDecision == 1)
    {
        cout<<"Wheel movement"<<endl;
        //myWheelOfFortune.wheelMovement();
    }
    else if(userDecision == 2)
    {
        cout<<"Going to the bank account"<<endl;
    }
}
int WheelOfFortune::moneyWonLose()
{
    return 0;
}


/*DEAL NO DEAL.CPP*/
/*=======================================================================================================================================================================*/
DealNoDeal::DealNoDeal()
{
    max = 1000;
    min = 1;
    arrayBriefcases[3][3];
    
}
// // DealNoDeal::DealNoDeal(int, int)
// // {
// //     //prints what the value in the briefcase is no matter what decision and then
// //     //adds money to bank 
// // }
void DealNoDeal::display()
{
    cout<<" _______     _______     _______  "<<endl;
    cout<<"|       |   |       |   |       | "<<endl;       
    cout<<"|   "<<seven<<"   |   |   "<<eight<<"   |   |   "<<nine<<"   | "<<endl;                
    cout<<"|_______|   |_______|   |_______| "<<endl;                     
    cout<<" _______     _______     _______  "<<endl;
    cout<<"|       |   |       |   |       | "<<endl;           
    cout<<"|   "<<six<<"   |   |   "<<five<<"   |   |   "<<four<<"   | "<<endl;     
    cout<<"|_______|   |_______|   |_______| "<<endl;    
    cout<<" _______     _______     _______  "<<endl;
    cout<<"|       |   |       |   |       | "<<endl; 
    cout<<"|   "<<one<<"   |   |   "<<two<<"   |   |   "<<three<<"   | "<<endl;
    cout<<"|_______|   |_______|   |_______| "<<endl;
    
}
void DealNoDeal::setBriefcaseValue()
{
    for(int i=0; i<3; i++)
    {
        for(int j=0; j<3; j++)
        {
            arrayBriefcases[i][j]=rand() % (max + min); //makes each briefcase value different (between $1 and $100)
        }
    }
    //reads from an array file and takes the users choice for what briefcase they
    //want and gives the briefcase value for that choice.
}
int DealNoDeal::playerChoice(int briefcasePick)
{
    int minValue = -100;
    int maxValue = 300;
    int maxValue1 = 4;
    int minValue1 = 1;
    int userBankOfferChoice;
    ofstream myfile ("bankAccount.txt");
    
    
    if(briefcasePick == 1){
        briefcaseValue = arrayBriefcases[2][0];
    }
    else if(briefcasePick == 2){
        briefcaseValue = arrayBriefcases[2][1];
    }
    else if(briefcasePick == 3){
        briefcaseValue = arrayBriefcases[2][2];
    }
    else if(briefcasePick == 4){
        briefcaseValue = arrayBriefcases[1][2];
    }
    else if(briefcasePick == 5){
        briefcaseValue = arrayBriefcases[1][1];
    }
    else if(briefcasePick == 6){
        briefcaseValue = arrayBriefcases[1][0];
    }
    else if(briefcasePick == 7){
        briefcaseValue = arrayBriefcases[0][0];
    }
    else if(briefcasePick == 8){
        briefcaseValue = arrayBriefcases[0][1];
    }
    else if(briefcasePick == 9){
        briefcaseValue = arrayBriefcases[0][2];
    }
    
    
    int randomAlternativeChoice = rand() % (maxValue + minValue);
    
    int bankerOfferRandom = rand() % (maxValue1 + minValue1);
    //makes it a 25% chance of the bank making a offer
    if(bankerOfferRandom == 1)
    {
        cout<<"YOU GOT AN OFFER FROM THE BANK!"<<endl;
        cout<<"The bank's offer is between -100 and 300"<<endl;
        cout<<"press 1 to keep your briefcase offer or press 2 to take the bank's offer"<<endl;
        cin>>userBankOfferChoice;
        if(userBankOfferChoice==2)
        {
            if(randomAlternativeChoice < 0) //if you lost money(is negative)
            {
                if(myfile.is_open())
                {
                    player.currentBalance = player.currentBalance + randomAlternativeChoice;
                    cout<<"You lost $"<<randomAlternativeChoice<<endl;
                    myfile<<"Balance after playing Deal or no Deal: "<<player.currentBalance<<endl;
                    cout<<"Your current balance is now at $"<<player.currentBalance<<endl;
                }
                else
                {
                    cout<<"file is not open"<<endl;
                }
            }
            else //if bank offer is positive
            {
                if(myfile.is_open())
                {
                    player.currentBalance = player.currentBalance + randomAlternativeChoice;
                    cout<<"You won $"<<randomAlternativeChoice<<endl;
                    myfile<<"Balance after playing Deal or no Deal: "<<player.currentBalance<<endl;
                    cout<<"Your current balance is now at $"<<player.currentBalance<<endl;
                }
                else
                {
                    cout<<"file is not open"<<endl;
                }
            }
        }
        else //if they want briefcase value
        {
            if(myfile.is_open())
            {
                player.currentBalance = player.currentBalance + briefcaseValue;
                myfile<<"Balance after playing Deal or no Deal: "<<player.currentBalance<<endl;
                cout<<"Your current balance is now at $"<<player.currentBalance<<endl;
            }
            else
            {
                cout<<"file is not open!"<<endl;
            }
        }
        
    }//end if
    else //if it didnt hit the randomizer and you automatically get the briefcase money
    {
        if(myfile.is_open())
        {
            player.currentBalance = player.currentBalance + briefcaseValue;
            myfile<<"Balance after playing Deal or no Deal: "<<player.currentBalance<<endl;
            cout<<"You won $"<<briefcaseValue<<endl;
            cout<<"Your current balance is now at $"<<player.currentBalance<<endl;
        }
        else{
            cout<<"file is not open"<<endl;
        }
    }//end else
    myfile.close();
    
    //uses a randomizer to get another dollar amount as an offer
}
void DealNoDeal::userBriefcaseChoice(int userPick)
{

        if(userPick==1){
            one = 0;
        }
        else if(userPick==2){
            two = 0;
        }
        else if(userPick==3){
            three = 0;
        }
        else if(userPick==4){
            four = 0;
        }
        else if(userPick==5){
            five = 0;
        }
        else if(userPick==6){
            six = 0;
        }
        else if(userPick==7){
            seven = 0;
        }
        else if(userPick==8){
            eight = 0;
        }
        else if(userPick==9){
            nine = 0;
        }

    //DealNoDeal::choice1=i;
}
// void DealNoDeal::userDealChoice(int j)
// {
//     DealNoDeal::choice2=j
// }


/*ROULETTE.CPP*/
/*=======================================================================================================================================================================*/

string to_lower(string s)
{
    for(int m=0; m<s.length(); m++)
    {
        s[m]=tolower(s[m]);
    }
    return s;
}

Roulette::Roulette()
{
    //player can only pick one of the options to bet on, and they place their 
    //bets and money grows depending on which choice and if you win
}

void Roulette::allChoices()
{
    string moneyBet;
    string userChoice;
    string moneyBet2;
    string inputBack;
    string inputBack1;
    string inputBack2;
    string inputBack3;
    
    int answer = 0;
    int i_userChoice = 0;
    int i_moneyBet=0;
    int i_moneyBet2=0;
    int blackRedChoice=0;
    
    int flag0 = 0;
    int flag1 = 0;
    int flag2 = 0;
    int flag3 = 0;
    
    int min1 = 1;
    int max1 = 32;
    int min2 = 1;
    int max2 = 2;
    int random1=0;
    int random2=0;
    ofstream myfile ("bankAccount.txt");
    
    while(answer!=3)
    {
        cout<<"RRRR         O O       U     U   L        EEEEEEEE   TTTTTTTTTTT   TTTTTTTTTTTT   EEEEEEEE      "<<endl;
        cout<<"R    R      O   O      U     U   L        E               T              T        E             "<<endl;
        cout<<"RRRR       O     O     U     U   L        E               T              T        E             "<<endl;
        cout<<"R         O       O    U     U   L        E               T              T        E             "<<endl;
        cout<<"R R       O       O    U     U   L        EEEEEE          T              T        EEEEEEE       "<<endl;
        cout<<"R  R       O      O    U     U   L        E               T              T        E             "<<endl;
        cout<<"R   R       O    O     U     U   L        E               T              T        E             "<<endl;
        cout<<"R     R      O O       UUUUUUU   LLLLLLL  EEEEEEEE        T              T        EEEEEEEE      "<<endl;
        
        cout<<endl;
        cout << "Welcome to Roulette!" <<endl;
        cout << "Choose to bet on a single number(1-32) or bet on red or black"<<endl;
        cout << "You can multiply your money by 10 if you pick the single number and win" << endl;
        cout << "You can double your money if you bet on red or black and win" <<endl;
        cout << "You will lose ALL of your money that you bet if you lose."<<endl;
        cout << "1. Single Number" << endl;
        cout << "2. Red or Black"  << endl;
        cout << "3. I don't want to play anymore" <<endl;
        
        cin>>answer;
        
        random1 = rand() % (max1 + min1);
        random2 = rand() % max2 + min2;

        switch(answer)
        {
            //single number
            case 1:
                cout << "How much money do you want to bet?" << endl;
                cin.ignore();
                getline(cin, moneyBet);
                i_moneyBet = stoi(moneyBet);

                cout << "What number do you want to bet on?(between 1 and 32)"<<endl;  
               // cin.ignore();
                getline(cin, userChoice);
                i_userChoice = stoi(userChoice);
                
                while(i_userChoice>32)
                {
                    cout<<"You must pick a number between 1 and 32. Try again: "<<endl;
                    //cin.ignore();
                    getline(cin, userChoice);
                    i_userChoice = stoi(userChoice);
                }

                if(random1 == i_userChoice)
                {
                    cout<<"YOU WON!"<<endl;
                    i_moneyBet = i_moneyBet*10; 
                    if (myfile.is_open())
                    {
                        player.currentBalance = player.currentBalance + i_moneyBet;
                        myfile<<"Balance after playing Roulette: "<<player.currentBalance<<endl;
                        cout<<"Your current balance is now at $"<<player.currentBalance<<endl;
                        cout<<endl;
                    }
                    else
                    {
                        cout<<"the file never opened "<<endl;
                    }
                    //stops menu from automatically printing out and makes user do a command to return to menu
                    while(inputBack2 == "")  
                    {
                        if(flag2 == 0) 
                        {
                            cout<<"Press any key to return to the menu"<<endl;
                            flag2 = 1; 
                        }
                        getline(cin, inputBack2);
                    }//end while
                }//end if
                else
                {
                    cout<<"You lost. The ball landed on "<<random1<<endl; 
                    if (myfile.is_open())
                    {
                        player.currentBalance = player.currentBalance - i_moneyBet; //makes player lose all money they bet
                        myfile<<"Balance after playing Roulette: "<<player.currentBalance<<endl;
                        cout << "Your current balance is now $"<<player.currentBalance<<endl;
                        cout<<endl;
                    }
                    else
                    {
                        cout<<"the file never opened "<<endl;
                    }
                    //stops menu from automatically printing out and makes user do a command to return to menu
                    while(inputBack3 == "")  
                    {
                        if(flag3 == 0) 
                        {
                            cout<<"Press any key to return to the menu"<<endl;
                            flag3 = 1; 
                        }
                        getline(cin, inputBack3);
                    }//end while
                }//end else
                break;
                
            //red or black    
            case 2: 
                cout << "How much money do you want to bet?" << endl;
                cin.ignore(); //clears the buffer so that other cins can occur
                getline(cin, moneyBet2);
                i_moneyBet2 = stoi(moneyBet2);
                cout << "Do you want to bet on black(1) or red(2)?"<<endl;  /////////////fixxxx to make where they type high or low
                cin>> blackRedChoice;
                
                while(blackRedChoice>2)
                {
                    cout<<"You must pick a number between 1 and 2. Try again: "<<endl;
                    cin>>blackRedChoice;
                }
                
                if(random2 == blackRedChoice)
                {
                    cout<<"YOU WON!"<<endl;
                    i_moneyBet2 = i_moneyBet2*2-i_moneyBet2; 
                    
                    if (myfile.is_open())
                    {
                        player.currentBalance = player.currentBalance + i_moneyBet2;
                        myfile<<"Balance after playing Roulette: "<<player.currentBalance<<endl;
                        cout<<"Your current balance is now at $"<<player.currentBalance<<endl;
                        cout<<endl;
                    }
                    else
                    {
                        cout<<"the file never opened "<<endl;
                    }
                    //stops menu from automatically printing out and makes user do a command to return to menu
                    while(inputBack1 == "")  
                    {
                        if(flag1 == 0) 
                        {
                            cout<<"Press any key to return to the menu"<<endl;
                            flag1 = 1; 
                        }
                        getline(cin, inputBack1);
                    }//end while
                }
                else 
                {
                    inputBack = "";
                    
                        cout<<"You lost."<<endl; ///////////make random high or low not 1 or 2
                        flag0 = 0;
                        if (myfile.is_open())
                        {
                            player.currentBalance = player.currentBalance - i_moneyBet2; //makes player lose all money they bet
                            myfile<<"Balance after playing Roulette: "<<player.currentBalance<<endl;
                            cout << "Your current balance is now $"<<player.currentBalance<<endl;
                            cout<<endl;
                            
                            if(flag0 == 0) 
                            {
                                cout<<"Press any key to return to the menu"<<endl;
                                flag0 = 1; //makes this line only print out once
                            }
                            getline(cin, inputBack);
                        }

                        else
                        {
                            cout<<"the file never opened "<<endl;
                        }//end else
                        
                        //stops menu from automatically printing out and makes user do a command to return to menu
                        while(inputBack == "")  
                        {
                            if(flag0 == 0) 
                            {
                                cout<<"Press any key to return to the menu"<<endl;
                                flag0 = 1; 
                            }
                            getline(cin, inputBack);
                        }//end while
                        flag0 = 0;
                }//end else
                break;
                
            //quit    
            case 3:
                cout<<"Good Bye!"<<endl;
                myfile.close();
                //return 0;
                break;
            
            default:
            cout<<"Invalid input."<<endl;
            break;   
        }//end switch
    
    }//end while
}


// int main()
// {
//     Roulette object;
//     object.allChoices();
//     return 0;
// }



//g++ -std=c++11
//./a.out