#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <random>
#include "DeckOfCards.h"
#include "Player.h"

const int MAX_FACE_COUNT = 13;
const int MAX_SUIT_COUNT = 4;

DeckOfCards deck;
std::vector<DeckOfCards::Card> cardDeck;
Player p1;
Player p2;
Player p3;
Player p4;

void Deal3Cards(std::vector<DeckOfCards::Card> cardDeck){
    for(int i = 0; i < 4; i++){
        if(i == 0){
            p1.DealCards(cardDeck);
        }
        else if(i == 1){
            p2.DealCards(cardDeck);
        }
        else if(i == 2){
            p3.DealCards(cardDeck);
        }
        else if(i == 3){
            p4.DealCards(cardDeck);
        }
    }
}

void showHand(){
    p1.showMyHand();
}

int main(){

    std::string face[MAX_FACE_COUNT] ={"Ace","2","3","4","5","6","7","8","9","10","Jack","Queen","King"};
    std::string suit[MAX_SUIT_COUNT] = {"Spades","Hearts","Diamonds","Clubs"};
    
    deck.initializingDeck(face, suit, MAX_FACE_COUNT, MAX_SUIT_COUNT);

    Deal3Cards(cardDeck);
    showHand();
    

    return 0;
}



