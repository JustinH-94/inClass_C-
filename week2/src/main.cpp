#include <iostream>
#include <cstdio>
#include <stdio.h>

class Foo{
    private:
        int someInt;
    public:
        void set_int(const int n);
        int get_int();
}

void Foo::set_int(const int n){
    this->someInt = n;
}

int Foo::get_int(){ return this->someInt;}


int main(){
    // std:: cout << "Hello World" << std::endl;
    // bool result = isPalindrome(9);
    // std:: cout << result << std:: endl;

    // foo(10);
    // funs::foo();
}

// namespace funs {
//     void foo();
// }
void foo(int  y = 10);

bool isPalindrome(int x){
    if(x < 0 || x <= 10){
        return false;
    }

    int rev =0, remainder;
    int original = x;
    while(x != 0 ){
        remainder = x % 10;
        rev = rev * 10 + remainder;
        x /= 10;
    }
    std:: cout << original << " " << rev << std:: endl;
    if(rev == original)
        return true;
    else   
        return false;
}


