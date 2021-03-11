//#include "DeckOfCards.h"
#include <vector>



class PlayerHand{    
    public:
        std::vector<DeckOfCards::Card> my_Hand;
        int my_CardCount = 5;
};

class Dealer{
    protected:
        int placePos;
        bool isDealer;
};

class Player : PlayerHand, Dealer{
    public:
        Player(){

        }

        void DealCards(std::vector<DeckOfCards::Card> cardDeck){
            my_Hand.insert(my_Hand.begin(),cardDeck.front());
        }

        void showMyHand(){
            showCards(my_Hand);
        }

        void showCards(std::vector<DeckOfCards::Card> my_Hand){
            for(DeckOfCards::Card c : my_Hand){
                std::cout << c.face<< " " << c.suit << std::endl;
            }
        }

        void SetPlacePos(int num){
            placePos = num;
        }

        void ClearHand(){
            my_Hand.clear();
        }

        std::vector<DeckOfCards::Card> ReturnHand(){
            return my_Hand;
        }

        void NewDealer(){
            isDealer = true;
        }

        void NotDealer(){
            isDealer = false;
        }
};

