#include <iostream>
#include <string>
#include <fstream>
#include <stdlib.h> //for random
#include "classFunctions.h"
using namespace std;

int main()
{
    PlayerMoney myPlayerMoney;
    WheelOfFortune myWheelOfFortune;
    DealNoDeal myDealNoDeal;
    Roulette myRoulette;
    
    ifstream inFile;
    int i_userInput = 0;
    int flag        = 0;
    int flag4       = 0;
    string i        = "";
    string line     = "";
    string input    = "";
    string inputBack4 = "";
    
    
    int choicePlayer;
    
    // inFile.open("bankAccount.txt");
    
    while (i_userInput!=5)
    {
   cout << " W          W  EEEEEE L        CCCC   OOOOOO    M     M    EEEEEE    TTTTTTT  OOOOOO     TTTTTTT H    H EEEEEE      CCCC   AAAA   SSSS IIIIIII NN   N  OOOOOO     !!!!!   "<<endl;                           
   cout << " W          W  E      L       C      O      O  M  M  M  M  E            T    O      O       T    H    H E          C      A    A  S       I    N N  N O      O     !!!    "<<endl;   
   cout << " W    WW    W  EEEE   L      C       O      O  M   MM   M  EEEE         T    O      O       T    HHHHHH EEEE      C       A    A  S S     I    N  N N O      O      !     "<<endl;        
   cout << "  W  W  W  W   E      L       C      O      O  M        M  E            T    O      O       T    H    H E          C      AAAAAA     S    I    N   NN O      O            "<<endl;         
   cout << "   WW    WW    EEEEEE LLLLLL   CCCC   OOOOOO   M        M  EEEEEE       T     OOOOOO        T    H    H EEEEEE      CCCC  A    A  SSSS IIIIIII N    N  OOOOOO       !     "<<endl;                                                    
                                                                                    
        cout << endl;
        cout << "Gamble in each game to try to win money!" << endl;
        cout << "If you lose all your money the game is over." << endl;
        cout << "Menu: " << endl;
        cout << "1. Wheel of Fortune" << endl;
        cout << "2. Deal or No Deal" << endl;
        cout << "3. Roulette" << endl;
        cout << "4. Look at your bank account" << endl;
        cout << "5. Quit"<<endl;
        // getline(cin, i);
        // int i_userInput = stoi(i);
        cin>>i_userInput;
        
        switch(i_userInput)
        {
            case 1: //wheel of fortune
                myWheelOfFortune.wheelMovement();
                break;
            
            case 2: //deal or no deal
                cout<<"Rules of the game:"<<endl;
                cout<<"Choose a briefcase, once you have picked a briefcase"<<endl;
                cout<<"you cannot choose that briefcase again."<<endl;
                cout<<"The bank randomly offers choose that you can pick instead of the briefcase."<<endl;
                cout<<endl;
                    for(int i=0; i<9; i++)
                    {
                        myDealNoDeal.display();
                        cout<<"Pick a briefcase! Each briefcase has between $1-$100"<<endl;
                        myDealNoDeal.setBriefcaseValue();
                        cin>>choicePlayer;
                        myDealNoDeal.playerChoice(choicePlayer);
                        
                        myDealNoDeal.userBriefcaseChoice(choicePlayer);
                        
                        
                    }
                    
                cout<<"Thanks for playing!"<<endl;
                while(inputBack4 == "")
                {
                    if(flag4 == 0)
                    {
                        cout<<"Press any key to return to the menu"<<endl;
                        flag4 = 1;
                    }
                    getline(cin, inputBack4);
                }
                //resets the flag so that if you want to access it a second time you can get to the menu again
                flag4=0;
                cout<<endl;
                
                break;
            
            case 3: //roulette
                myRoulette.allChoices();
                break;
            case 4: //bank account
                inFile.open("bankAccount.txt");
                if(inFile.is_open())
                {
                    input = "";
                while(getline(inFile, line))
                    {
                        cout<<line<<endl;
                    }//end while
                    while(input == "") //allows user to type anything and then press enter to go to the menu
                    {
                        if(flag == 0) 
                        {
                            cout<<"Press any key to return to the menu"<<endl;
                            flag = 1; //makes this line only print out once
                        }
                        getline(cin, input);
                    }
                    //resets the flag so that if you want to access it a second time you can get to the menu again
                    flag = 0;
                }//end if
                else
                {
                    cout<<"File is not open!!!"<<endl;
                }
                inFile.close();
                break;
                
            case 5: //quit
                cout<<"Good bye!"<<endl;
                //"you ended the game with $$"
                
                break;
            
        }
    }//end while
    //intitalize current balance(10,000) should only happen once
    //launch game menu until deciding to exit or lose all money
    
}//end main