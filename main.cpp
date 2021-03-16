/* This main file demonstrates a program that ask the user to enter a positve integer
and prints random snowmen according to the input of the user.
*/

#include <iostream>
#include "snowman.hpp"

using namespace std;

// Returns a random digit in the range 1-4
int random_digit(){
    int num = rand() % 4 + 1;   
    return num;
}

// Returns a random number with eight digits in the range 1-4
int random_num(){
    string str = "";
    for(int i = 0; i < 8; i++){
        int num = random_digit();
        str += std::to_string(num);
    }
    int num = atoi(str.c_str()); // Converts the string to integer 
    return num;
}

// Prints random snowmen
int main(){
    int amount;
    cout << "Enter the numbers of snowmans that you want to print: ";
    cin >> amount;
    for(int i = 1; i <= amount; i++){
        int num = random_num();
        cout << "Snowman number: " << i << endl;
        cout << ariel::snowman(num) << endl;
    }  
    return 0;
}