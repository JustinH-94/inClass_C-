#include <iostream>
#include <string>
#include <stdlib.h>

int intMax = 2147483647;
int intMin = -2147483648;

std::string GetNum(){
    std::string numString;
    std::cout << "Enter a number: ";
    std::cin >> numString;
    return numString;
}

int myAtoi(std::string numString){
    bool isWhiteSpace = true;
    int sign = 1;
    int whiteSpaceCounter = 0;
    int num = 0;

    if(numString.length() == 0){
        return 0;
    }
    while((whiteSpaceCounter < numString.length()) && numString[whiteSpaceCounter] == ' '){
        whiteSpaceCounter++;
    }
    if(whiteSpaceCounter < numString.length() && (numString[whiteSpaceCounter] == '+' || numString[whiteSpaceCounter] == '-')){
        sign = (numString[whiteSpaceCounter++] == '-') ? -1 : 1;
    }
    while(whiteSpaceCounter < numString.length() && numString[whiteSpaceCounter] >= '0' && numString[whiteSpaceCounter] <= '9'){
        if(num > intMax / 10 || (num == intMax /10 && numString[whiteSpaceCounter] - '0' > intMax %10)){
            return (num == 1) ? intMax : intMin;
        }    
        num = num * 10 + (numString[whiteSpaceCounter++] - '0');
    }
    return num * sign;
}

int main(){
    std::string numString = GetNum();
    int num = myAtoi(numString);
    std::cout << num << std::endl;
}