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

        int set(std::string suit, std::string face){
            for(int i = 0; i < 5; i++){
                if(my_Hand[i].face == face && my_Hand[i].suit == suit){
                    return i;
                }
            }
            return 0;
        }

        void EraseCard(std::string suit){
            for( DeckOfCards::Card c : my_Hand){
                if(c.suit == suit){
                    my_Hand.erase(my_Hand.begin() + set(c.suit, c.face));
                }
            }
        }

        DeckOfCards::Card PlayCard(std::string TrumpSuit, std::string secondBestSuit){
            DeckOfCards::Card temp;
            for(DeckOfCards::Card c : my_Hand){//searches for best possible card
                    if(c.suit == TrumpSuit && (c.face == "Jack" || c.face =="Ace")){
                        my_Hand.erase(my_Hand.begin() + set(c.suit, c.face));
                        return c;
                    } else if (c.suit == secondBestSuit && c.face == "Jack"){
                        return c;
                    }
            }
            for(DeckOfCards::Card c : my_Hand){
                if(c.suit == TrumpSuit){//if no best card is available, then any card with the same trump suit is placed.
                    return c;
                }
            }
            for(DeckOfCards::Card c : my_Hand){
                if(c.face != "Jack" || c.face != "Ace"){
                    return c;
                }
            }

            return temp;
        }

        std::string SetTrumpSuit(){
            int H = 0, D = 0, S = 0, C = 0;
            for(DeckOfCards::Card c : my_Hand){
                if(c.suit == "Hearts"){
                    if(c.face == "Jack"){
                        my_Hand.erase(my_Hand.begin() + set(c.suit, c.face));
                        return "Hearts";
                    }
                    H++;
                } else if(c.suit == "Diamonds"){
                    if(c.face == "Jack"){
                        my_Hand.erase(my_Hand.begin() + set(c.suit, c.face));
                        return "Diamonds";
                    }
                    D++;
                } else if(c.suit == "Spades"){
                    if(c.face == "Jack"){
                        my_Hand.erase(my_Hand.begin() + set(c.suit, c.face));
                        return "Spades";
                    }
                    S++;
                } else if(c.suit == "Clubs"){
                    if(c.face == "Jack"){
                        my_Hand.erase(my_Hand.begin() + set(c.suit, c.face));
                        return "Clubs";
                    }
                    C++; 
                }
            }

            if(H + D > S + C && H > D) 
                return "Hearts";
            else if(D + H > S + C && D > H)
                return "Diamonds";
            else if(D + H < S + C && S > C)
                return "Spades";
            else if(D + H < S + C && C > S)
                return "Clubs";

            return "";
        }
};

