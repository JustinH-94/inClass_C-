#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <random>
#include "DeckOfCards.h"

const int MAX_FACE_COUNT = 13;
const int MAX_SUIT_COUNT = 4;

DeckOfCards deck;

int main(){
    

    std::string face[MAX_FACE_COUNT] ={"Ace","2","3","4","5","6","7","8","9","10","Jack","Queen","King"};
    std::string suit[MAX_SUIT_COUNT] = {"Spades","Hearts","Diamonds","Clubs"};
    
    deck.initializingDeck(face, suit, MAX_FACE_COUNT, MAX_SUIT_COUNT);
    

    return 0;
}


