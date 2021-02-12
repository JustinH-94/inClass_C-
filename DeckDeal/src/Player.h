#include "DeckOfCards.h"
#include <vector>



class PlayerHand{    
    public:
        std::vector<DeckOfCards::Card> my_Hand;
        int my_CardCount = 5;
};

class Player : PlayerHand, Dealer{
    public:
        Player(std::vector<DeckOfCards::Card> myHand, bool _isDealer){
            isDealer = _isDealer;
            my_Hand = myHand;
        }

        void DealCards(std::vector<DeckOfCards::Card> cardDeck){
            for(int i = 0; i < 4; i++){
                for(int j = 0; j < 3; j++){
                    if(i = 0){

                    }
                    else if(i = 1){

                    }
                    else if(i = 2){

                    }
                    else if(i = 3){
                        
                    }
                }
            }
        }
};

class Dealer{
    protected:
        bool isDealer;
};