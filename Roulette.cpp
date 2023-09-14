#include <iostream>
using namespace std;

int main(){
    int age;
    int balance = 1000;

    cout << "Welcome! \n"
            "How old are you?: ";
    cin >> age;

    if (age >= 18){
        cout << "You have " << balance << "kr in your balance" << endl;

        cout << "How much money do you want to bet?: ";
    } else{
        cout << "You're too young to play!";
    }
    
    return 0;
}