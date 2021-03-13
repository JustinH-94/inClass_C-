#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <random>
#include <sstream>
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
std::string secondBestSuit;
std::string playerPlay;

bool play = true;
bool isTrumpSet = false;
bool allPlayersHaveCards = true;

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
    std::cout<< std::endl;
    p3.showMyHand();
    std::cout<< std::endl;
    p4.showMyHand();
    std::cout<< std::endl;

}

void setSecondBestSuit(std::string TrumpSuit){
    if(TrumpSuit == "Spades"){
        secondBestSuit = "Clubs";
    }
    if(TrumpSuit == "Clubs"){
        secondBestSuit = "Spades";
    }
    if(TrumpSuit == "Hearts"){
        secondBestSuit = "Diamonds";
    }
    if(TrumpSuit == "Diamonds"){
        secondBestSuit = "Hearts";
    }

}

std::vector<DeckOfCards::Card> TopSuit(std::vector<DeckOfCards::Card> cardDeck){
    for(DeckOfCards::Card c : cardDeck){      
                TrumpSuit = c.suit;
                setSecondBestSuit(TrumpSuit);
                cardDeck.erase(cardDeck.begin());
                return cardDeck;
            }
    return cardDeck;
}

float SetRank(std::vector<DeckOfCards::Card> hand){
    float rankScore = 0;
    for(DeckOfCards::Card c : hand){
        for(DeckOfCards::Card t : deck.bestHand){
            if (c.face == t.face && t.suit == c.suit && c.face == "Jack")
            {
                rankScore += 0.50;
            }
            else if(c.face == t.face && t.suit == c.suit && c.face != "Jack"){
                rankScore += 0.25;
            }
        }
    }
    return rankScore;
}

bool BustOrRedeal(float rank){
    if(rank >= 0.75){
        return true;
    }
    return false;
}

bool HandRank(int dealVal){
    int playerChecked = 0;
    bool playTrump = false;
    for(int i = dealVal; i <= 4; i++){
        if(i == 1){
            tempHand = p1.ReturnHand();
            p1Rank = SetRank(tempHand);
            std::cout << p1Rank << "p1" <<std::endl;
            playTrump = BustOrRedeal(p1Rank);
        }
        else if(i == 2){
            tempHand = p2.ReturnHand();
            p2Rank = SetRank(tempHand);
            std::cout << p2Rank << "p2"<<std::endl;
            playTrump = BustOrRedeal(p2Rank);
        }
        else if(i == 3){
            tempHand = p3.ReturnHand();
            p3Rank = SetRank(tempHand);
            std::cout << p3Rank << "p3"<<std::endl;
            playTrump = BustOrRedeal(p3Rank);
        }
        else if(i == 4){
            tempHand = p4.ReturnHand();
            p4Rank = SetRank(tempHand);
            std::cout << p4Rank << "p4"<<std::endl;
            playTrump = BustOrRedeal(p4Rank);
            i=0;
        }
        tempHand.clear();
        if(playTrump){
            std::cout << TrumpSuit << " is being played" << std::endl;
            isTrumpSet = true;
            return playTrump;
            break;
        }
        
        if(playerChecked == 3){ break;}
        playerChecked++;
    }
    return false;
} 

void SetBestHand(){
    for(int i = 0; i < 7; i++){
        DeckOfCards::Card card;
        if(i == 0){
            card = {TrumpSuit, "Jack"};
            
        } else if (i == 1){
            card = {secondBestSuit, "Jack"};
        }
        else if (i == 2){
            card = {TrumpSuit, "Ace"};
        }
        else if (i == 3){
            card = {TrumpSuit, "King"};
        }
        else if (i == 4){
            card = {TrumpSuit, "Queen"};
        }
        else if (i == 5){
            card = {TrumpSuit, "10"};
        }
        else if (i == 6){
            card = {TrumpSuit, "9"}; 
        }
        deck.settingBestHand(card);
    }
}

bool PlayGame(){
    std::cout << "Play a new game of Euchre? (Enter 1: yes, Enter 2: no)" << std::endl;
    std::cin >> playerPlay;
    if(playerPlay =="1"){
        return true;
    }
    else{
        return false;
    }
}

void ClearHands(){
    p1.ClearHand();
    p2.ClearHand();
    p3.ClearHand();
    p4.ClearHand();
}

void SetDealer(int dealerVal){
    if(dealerVal == 1){
        p1.NewDealer();
    }
    else{
        p1.NotDealer();
    }
    if(dealerVal == 2){
        p2.NewDealer();
    }
    else{
        p2.NotDealer();
    }
    if(dealerVal == 3){
        p3.NewDealer();
    }
    else{
        p3.NotDealer();
    }
    if(dealerVal == 4){
        p4.NewDealer();
    }
    else{
        p4.NotDealer();
    }
}


std::vector<DeckOfCards::Card> DealCards(std::vector<DeckOfCards::Card> cardDeck){
    cardDeck = Deal3Cards(cardDeck);
    cardDeck = Deal2Cards(cardDeck);
    return cardDeck;
}

void NextPlayerSetTrump(int TrumpSetter){
    TrumpSetter++;
    if(TrumpSetter == 5){
        TrumpSetter = 1;
    }
    if(TrumpSetter == 1){
        TrumpSuit = p1.SetTrumpSuit();
    }
    if(TrumpSetter == 2){
        TrumpSuit = p2.SetTrumpSuit();
    }
    if(TrumpSetter == 3){
        TrumpSuit = p3.SetTrumpSuit();
    }
    if(TrumpSetter == 4){
        TrumpSuit = p4.SetTrumpSuit();
    }
}


void PlayerTurn(int dealerVal){
    int counter  = 0;
    while(counter < 4){
        if(dealerVal == 5){
            dealerVal == 1;
        }
        if(dealerVal == 1){

        } else if (dealerVal == 2){

        } else if(dealerVal == 3){
        
        } else if(dealerVal == 4){

        }
        
    }
}

int main(){

    std::string face[MAX_FACE_COUNT] ={"Ace","9","10","Jack","Queen","King"};
    std::string suit[MAX_SUIT_COUNT] = {"Spades","Hearts","Diamonds","Clubs"};
    while(PlayGame()){
        int dealerVal = 1;
        int temp = dealerVal;
        ClearHands();
        cardDeck = deck.initializingDeck(face, suit, MAX_FACE_COUNT, MAX_SUIT_COUNT);
        SetDealer(dealerVal);
        cardDeck = DealCards(cardDeck);
        showHand();
        cardDeck = TopSuit(cardDeck);
        SetBestHand();
        
        HandRank(dealerVal);

        

        while(allPlayersHaveCards){
            if(!isTrumpSet){
                std::cout << "No one trumped. Player " << temp++ << " is picking next trump." << std::endl;
                NextPlayerSetTrump(dealerVal);            
                SetBestHand();
            }
            std::cout << "The Shown Top Suit is: " << TrumpSuit << std::endl;   
            allPlayersHaveCards = false;
            dealerVal++;
        }
        isTrumpSet = false;
    }

    
    return 0;
}



