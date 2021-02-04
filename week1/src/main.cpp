#include <iostream>

void isPalindrome(int x);

int main(){
    int num = 0;
    std:: cout << "Enter an integer: ";
    std:: cin >> num;
    isPalindrome(num);
}

void isPalindrome(int x){
    int ogNum = x;
    int digit = 0;
    int mirrored = 0;

        
    while(x != 0){
        digit = x % 10;
        mirrored = (mirrored * 10) + digit;
        x = x / 10;
    }
        
    if(ogNum == mirrored){
        std::cout << "It is a palindrome number" << std::endl;
    }
    else{
        std::cout << "It is not a palindrome number" << std::endl;
    }
}