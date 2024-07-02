// TASK 1 
// NUMBER GUESSING GAME
// Create a program that generates a random number and asks the user to guess it. Provide feedback on whether the guess is too high or too low until the user guesses the correct number.

#include<iostream>
#include<cstdlib>
#include<stdlib.h>

using namespace std;

int main(){
    cout << "\n\t\t\tWelcome to GuessTheNumber game!" <<endl;
    cout<<"The rules are simple: "<<endl;
    cout << "1. You have to guess a number between 1 and 100. "<<endl;
    cout << "2. You'll have limited choices based on the level you choose.\n\t\t\t\tGood Luck!" << endl;

    while(true){
        cout << "\nEnter the difficulty level: \n";
        cout << "1 for easy!\n";
        cout << "2 for medium!\n";
        cout << "3 for difficult!\n";
        cout << "0 for ending the game!\n"<< endl;

        int choice;
        cin>>choice;

        int ranNum = (rand() % (100 - 1) + 1);

        switch (choice)
        {
        case 1:{
            cout<<"You play it easy"<<endl;

            cout<<"You get 10 choices to guess the secret number between 1 to 100"<<endl;

            int c = 10;

            int i = 0;

            for(i=0;i<c;i++){
                cout<<"Choice Left: "<<c - i<<endl;

                int playerInput;
                cout<<"Enter a number: ";
                cin >> playerInput;

                if(playerInput > 0 && playerInput <= 100){

                if (playerInput == ranNum) {
                cout<<"Well played! You won :)"<<endl;
                break;
                }
                else if(playerInput < ranNum){
                    cout<<"The number choosen is small"<<endl;
                }
                else {
                    cout<<"The number choosen is large"<<endl;
                }

                }

                else {
                    cout<<"Enter a valid choice between 1 to 100"<<endl;
                }
                }

                if(i == c) cout<<"You lose! Better luck next time..."<<endl;
                break;
            }

            case 2:
            {
                cout << "Way to level up" << endl;

                cout << "You get 7 choices to guess the secret number between 1 to 100" << endl;

                int c = 7;

                int i = 0;

                for (i = 0; i < c; i++)
                {
                    cout << "Choice Left: " << c - i << endl;

                    int playerInput;
                    cout << "Enter a number: ";
                    cin >> playerInput;

                    if (playerInput > 0 && playerInput <= 100)
                    {

                        if (playerInput == ranNum)
                        {
                            cout << "Well played! You won :)" << endl;
                            break;
                        }
                        else if (playerInput < ranNum)
                        {
                            cout << "The number choosen is small" << endl;
                        }
                        else
                        {
                            cout << "The number choosen is large" << endl;
                        }
                    }

                    else
                    {
                        cout << "Enter a valid choice between 1 to 100" << endl;
                    }
                }

                if (i == c)
                    cout << "You lose! Better luck next time..." << endl;

                    break;
            }

            case 3:
            {
                cout << "Hard Level" << endl;

                cout << "You get 5 choices to guess the secret number between 1 to 100" << endl;

                int c = 5;

                int i = 0;

                for (i = 0; i < c; i++)
                {
                    cout << "Choice Left: " << c - i << endl;

                    int playerInput;
                    cout << "Enter a number: ";
                    cin >> playerInput;

                    if (playerInput > 0 && playerInput <= 100)
                    {

                        if (playerInput == ranNum)
                        {
                            cout << "Well played! You won :)" << endl;
                            break;
                        }
                        else if (playerInput < ranNum)
                        {
                            cout << "The number choosen is small" << endl;
                        }
                        else
                        {
                            cout << "The number choosen is large" << endl;

                        }
                    }

                    else
                    {
                        cout << "Enter a valid choice between 1 to 100" << endl;
                    }
                }

                if (i == c)
                    cout << "You lose! Better luck next time..." << endl;
                break;
            }

            case 0:{
                exit(0);
                break;
            }

            default:  cout<<"Enter a valid input";
        }
        }
    

    return 0;
}


