#include<iostream>

extern int add(int , int);
int sub(int , int);

int main() {

int number1 , number2;

std::cout << "number 1: ";
std::cin >> number1;

std::cout << "number 2:";
std::cin >> number2;

std::cout << "Addition of two numbers: " << add(number1,number2);
std::cout << "onsubtracti of two numbers: " << sub(number1,number2);

return 0;
}
