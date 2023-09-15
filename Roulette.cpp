#include <iostream>
using namespace std;

int main(){
    int age;
    int bet;
    int betOnColor;
    int balance = 1000;
    bool number;
    bool color;

    cout << "Welcome!\n"
            "How old are you?: ";
    cin >> age;

    if (age >= 18){
        cout << "You have " << balance << "kr in your balance." << endl;

        do {
            cout << "You need to bet an amount of money. (Type the amount you want to bet)\n"
                "1. 100kr\n"
                "2. 300kr\n"
                "3. 500kr\n"
                "How much do you want to bet?: ";
        cin >> bet;
        } while (bet != 100 && bet != 300 && bet != 500);

        do {
            cout << "You also need to bet on a number or a color. (1 for number, 2 for color)\n"
                "1. number\n"
                "2. color\n"
                "Do you want to bet on a number or a color?: ";
        cin >> betOnColor;
        } while (betOnColor != 1 && betOnColor != 2);

        switch (betOnColor){
            case 1:
                cout << bet;
                number = true;
                break;
            case 2:
                cout << bet;
                color = true;
                break;
        }



    } else{
        cout << "You're too young to play!";
    }
    
    return 0;
}