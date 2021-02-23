#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <random>
#include "DeckOfCards.h"
#include "Player.h"

const int MAX_FACE_COUNT = 6;
const int MAX_SUIT_COUNT = 4;

DeckOfCards deck;
std::vector<DeckOfCards::Card> cardDeck;
std::vector<DeckOfCards::Card> tempHand;
Player p1;
Player p2;
Player p3;
Player p4;

float p1Rank, p2Rank, p3Rank, p4Rank;

std::string TrumpSuit;

std::vector<DeckOfCards::Card> Deal3Cards(std::vector<DeckOfCards::Card> cardDeck){
    for(int j = 0; j < 3; j++){
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
            cardDeck.erase(cardDeck.begin());
        }
    }
    return cardDeck;  
}

std::vector<DeckOfCards::Card> Deal2Cards(std::vector<DeckOfCards::Card> cardDeck){
    for(int j = 0; j < 2; j++){
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
                cardDeck.erase(cardDeck.begin());
            }
        }
    return cardDeck;    
}

void showHand(){
    std::cout<< std::endl;
    p1.showMyHand();
    std::cout<< std::endl;
    p2.showMyHand();
    std::cout<< std::endl;

}

std::vector<DeckOfCards::Card> TopSuit(std::vector<DeckOfCards::Card> cardDeck){
    for(DeckOfCards::Card c : cardDeck){      
                TrumpSuit = c.suit;
                cardDeck.erase(cardDeck.begin());
                return cardDeck;
            }
    return cardDeck;
}

float SetRank(std::vector<DeckOfCards::Card> hand){
    float rankScore = 0;
    for(DeckOfCards::Card c : hand){
        if(c.suit == TrumpSuit){
            rankScore++;
        }
        else{
            rankScore += 0.5f;
        }
    }
    return rankScore;
}

void HandRank(){
    for(int i = 0; i < 4; i++){
                if(i == 0){
                    tempHand = p1.ReturnHand();
                    p1Rank = SetRank(tempHand);
                }
                else if(i == 1){
                    tempHand = p2.ReturnHand();
                    p2Rank = SetRank(tempHand);
                }
                else if(i == 2){
                    tempHand = p3.ReturnHand();
                    p3Rank = SetRank(tempHand);
                }
                else if(i == 3){
                    tempHand = p4.ReturnHand();
                    p4Rank = SetRank(tempHand);
                }
                tempHand.clear();
            }
} 




int main(){

    std::string face[MAX_FACE_COUNT] ={"Ace","9","10","Jack","Queen","King"};
    std::string suit[MAX_SUIT_COUNT] = {"Spades","Hearts","Diamonds","Clubs"};
    
    cardDeck = deck.initializingDeck(face, suit, MAX_FACE_COUNT, MAX_SUIT_COUNT);

    cardDeck = Deal3Cards(cardDeck);
    cardDeck = Deal2Cards(cardDeck);
    showHand();
    cardDeck = TopSuit(cardDeck);
    HandRank();
    std::cout << p1Rank << " " << p2Rank << std::endl;

    
    return 0;
}



