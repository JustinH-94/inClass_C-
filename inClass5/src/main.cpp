#include <iostream>
#include <string>
#include <stdlib.h>

std::string GetNum(){
    std::string numString;
    std::cout << "Enter a number: " << std::endl;
    std::cin >> numString;
    return numString;
}

int main(){
    std::string numString = GetNum();
    int b = atoi(numString.c_str());
    std::cout << b << std::endl;
    return 0;
}