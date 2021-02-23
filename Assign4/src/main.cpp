#include <iostream>
#include <string>
#include <vector>

int lengthOfLongestSubstring(std::vector<char> c){
    int counter = 0;

    for(int i = 0; i < c.capacity(); i++){
        for(int j = i + 1; j < c.capacity(); j++){
            counter++;
            if(c[i] == c[j]){
                return counter;
            }
        }
    }
    return counter;
}

int main(){
    std::string input;
    int counter;

    std::cout << "Enter an input and this program will display the longest amount of characters without a repeat: ";
    std::cin >> input;

    std::vector<char> c(input.begin(), input.end());

    counter = lengthOfLongestSubstring(c);
    std::cout << counter << std::endl;

    return 0;
}