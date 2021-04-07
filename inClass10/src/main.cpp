#include <iostream>
#include <cmath>
int Divide(int dividend, int divisor){
    bool isWhole = true;
    int counter = 0;
    while(isWhole){
        if(divisor > 0){
            dividend -= divisor;
            if(dividend >= 0){
                counter++;
            }
            else{
                return counter;
            }
        }else if (divisor < 0){
            dividend += divisor;
            if(dividend >= 0){
                counter++;
            }
            else{
                return counter*-1;
            }
        }
    }
    return counter;
}

int main(){
    int dividend, divisor;
    std::cout << "Enter Dividend: ";
    std::cin >> dividend;
    std::cout << "Enter Divisor: ";
    std::cin >> divisor;

    int result = Divide(dividend, divisor);
    std::cout << result << std::endl << std::endl;
}