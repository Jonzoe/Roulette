#include <iostream>
#include <ctime>
using namespace std;
int GenerateRandomNumber();

int main(){
    // Variables.
    int age, bet, playOnNumOrCol, balance = 1000, randomNumber, insertedNumber, insertedColor, totalWinToday = 0, checkNumber, quit, playAgain;
    bool number, color, play = true;

    // Welcomes the user.
    cout << "Welcome!\n"
            "How old are you?: ";
    cin >> age;

    while(play ==  true){
        // If the age of the user is 18 or above, the user wants to play again and has 100 kr or more in their balance they get to play.
        if (age >= 18 && balance >= 100){
            cout << "You have " << balance << " kr in your balance." << endl;

            // The amount of monety the user wants to bet.
            do {
                cout << "You need to bet an amount of money. (Type in the amount you want to bet)\n"
                    "1. 100 kr\n"
                    "2. 300 kr\n"
                    "3. 500 kr\n"
                    "How much do you want to bet?: ";
            cin >> bet;
            } while (bet != 100 && bet != 300 && bet != 500 || bet > balance);

            // Asks the user if it wants to play on number or color.
            do {
                cout << "You also need to play on a number or a color. (Type 1 for number, 2 for color)\n"
                    "1. Number\n"
                    "2. Color\n"
                    "Do you want to play on a number or a color?: ";
            cin >> playOnNumOrCol;
            } while (playOnNumOrCol != 1 && playOnNumOrCol != 2);

            switch (playOnNumOrCol){
                // Activates if the user wanted to play on number.
                case 1:
                    number = true;

                    // Asks the user what number it wants to play on.
                    do {
                    cout << "You need to pick a number between 1 and 36 to bet on (Type in the number you want to bet on)\n"
                        "What number do you want to bet on?: ";
                    cin >> insertedNumber;
                    } while (insertedNumber < 1 && insertedNumber > 36);

                    checkNumber = GenerateRandomNumber();

                    // Checks if the users number is the same as the wheels.
                    if (insertedNumber == checkNumber){
                        balance += bet*10;
                        totalWinToday += bet*10;
                        cout << "You played on "<< insertedNumber << " and the number on the wheel where " << checkNumber << " so you won!" << endl;
                        cout << "You won " << bet*2 << " kr this round" << endl;
                        cout << "Your new balance is: " << balance << " kr" << endl;

                        if (totalWinToday >= 0){
                            cout << "You have won this much today: " << totalWinToday << " kr" << endl;
                        }
                        else{
                            cout << "You have lost this much today: " << totalWinToday << " kr" << endl;
                        }
                    }
                    else{
                        balance -= bet;
                        totalWinToday -= bet;
                        cout << "You played on "<< insertedNumber << " and the number on the wheel where " << checkNumber << " so you unfortunately lost!" << endl;
                        cout << "You lost " << bet << " kr this round" << endl;
                        cout << "Your new balance is: " << balance << " kr" <<endl; 

                        if (totalWinToday >= 0){
                            cout << "You have won this much today: " << totalWinToday << " kr" << endl;
                        }
                        else{
                            cout << "You have lost this much today: " << totalWinToday << " kr" << endl;
                        }
                    }
                    break;

                // Activates if the user wanted to play on color.
                case 2:
                    color = true;

                    // Asks the user what color it wants to play on.
                    do {
                    cout << "You need to pick a color between red and black to bet on (Type 1 for red, 2 for black. Black is even and red is odd)\n"
                        "1. Red\n"
                        "2. Black\n"
                        "What color do you want to bet on?: ";
                    cin >> insertedColor;
                    } while (insertedColor != 1 && insertedColor != 2);

                    checkNumber = GenerateRandomNumber();

                    // Checks if the wheels number and the users color corresponds to each other.
                    // Played on black and the wheels number were even.
                    if (checkNumber % 2 == 0 && insertedColor == 2){ 
                        balance += bet*2;
                        totalWinToday += bet*2;
                        cout << "You played on black and the number on the wheel where even (" << checkNumber << ") so you won!" << endl;
                        cout << "You won " << bet*2 << " kr this round" << endl; 
                        cout << "Your new balance is: " << balance << " kr" << endl;

                        if (totalWinToday >= 0){
                            cout << "You have won this much today: " << totalWinToday << " kr" << endl;
                        }
                        else{
                            cout << "You have lost this much today: " << totalWinToday << " kr" << endl;
                        }
                    }
                    // Played on black and the wheels number were odd.
                    else if(checkNumber % 2 == 1 && insertedColor == 2){ 
                        balance -= bet;
                        totalWinToday -= bet;
                        cout << "You played on black and the number on the wheel where odd (" << checkNumber << ") so you unfortunately lost!" << endl;
                        cout << "You lost " << bet << " kr this round" << endl; 
                        cout << "Your new balance is: " << balance << " kr" << endl; 

                        if (totalWinToday >= 0){
                            cout << "You have won this much today: " << totalWinToday << " kr" << endl;
                        }
                        else{
                            cout << "You have lost this much today: " << totalWinToday << " kr" << endl;
                        }
                    }
                    // Played on red and the wheels number were even.
                    else if(checkNumber % 2 == 0 && insertedColor == 1){ 
                        balance -= bet;
                        totalWinToday -= bet;
                        cout << "You played on red and the number on the wheel where even (" << checkNumber << ") so you unfortunately lost!" << endl;
                        cout << "You lost " << bet << " kr this round" << endl;
                        cout << "Your new balance is: " << balance << " kr" << endl; 

                        if (totalWinToday >= 0){
                            cout << "You have won this much today: " << totalWinToday << " kr" << endl;
                        }
                        else{
                            cout << "You have lost this much today: " << totalWinToday << " kr" << endl;
                        }
                    }
                    // Played on red and the wheels number were odd.
                    else{ 
                        balance += bet*2;
                        totalWinToday += bet*2;
                        cout << "You played on red and the number on the wheel where odd (" << checkNumber << ") so you won!" << endl;
                        cout << "You won " << bet*2 << " kr this round" << endl;  
                        cout << "Your new balance is: " << balance << " kr" << endl;

                        if (totalWinToday >= 0){
                            cout << "You have won this much today: " << totalWinToday << " kr" << endl;
                        }
                        else{
                            cout << "You have lost this much today: " << totalWinToday << " kr" << endl;
                        }
                    }
                    break;
            }
            // Asks the user if it wants to play again or not.
            do {
            cout << "Do you want to play again (Type 1 for yes, 2 for no.)\n"
                "1. Yes\n"
                "2. No\n"
                "Do you want to play again?: ";
            cin >> playAgain;
            } while (playAgain != 1 && playAgain != 2);

            if(playAgain == 1){
                continue;
            }
            else{
                cout << "Thanks for playing, have a great day!";
                play = false;
                break;
            }
        }
        else if(balance < 100){
            cout << "You don't have at least 100 kr in your balance to play with!";
            break;
        }
        else{
            cout << "You are too young to play!";
            break;
        }
    }
    return 0;
}

// Generates a random number between 1 and 36.
int GenerateRandomNumber(){
    int randomNumber;
    srand(time(0));
    randomNumber = rand() % 36 + 1;
    return randomNumber;
}