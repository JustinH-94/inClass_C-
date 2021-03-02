#include<iostream>
#include <string>
#include <vector>
#include <algorithm>

class DeckOfCards{
    public:

        struct Card{
            std::string suit;
            std::string face;
        };
        //Card TrumpCard;
        std::vector<Card> cardDeck;
        std::vector<Card> bestHand;

        void displayDeck(std::vector<Card> const &cardDeck){
            for(Card c : cardDeck){
                std::cout << c.face<< " " << c.suit << std::endl;
            }
        }


        void settingDeck(std::string face[], std::string suit[], int MAX_SUIT_COUNT, int MAX_FACE_COUNT){
            for(int i = 0; i < MAX_SUIT_COUNT; i++){
                    for(int j = 0; j <MAX_FACE_COUNT; j++){
                        Card card = {suit[i], face[j]};
                        cardDeck.push_back(card);
                    }
                }
        }

        void settingBestHand(Card card){
            bestHand.push_back(card);
        }

        std::vector<Card> initializingDeck(std::string face[], std::string suit[], int MAX_FACE_COUNT, int MAX_SUIT_COUNT){
            cardDeck.clear();
            bestHand.clear();
            settingDeck(face, suit, MAX_SUIT_COUNT, MAX_FACE_COUNT);
            std::random_shuffle(std::begin(cardDeck),std::end(cardDeck));
            displayDeck(cardDeck);
            return cardDeck;
        }
        std::vector<Card> TopSuit(std::vector<Card> cardDeck){
            for(Card c : cardDeck){
                std::cout << c.suit << std::endl;
                return cardDeck;
            }
            return cardDeck;
        }
};