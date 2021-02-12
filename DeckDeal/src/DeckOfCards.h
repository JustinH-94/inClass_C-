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

        std::vector<Card> cardDeck;

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

        void initializingDeck(std::string face[], std::string suit[], int MAX_FACE_COUNT, int MAX_SUIT_COUNT){
            settingDeck(face, suit, MAX_SUIT_COUNT, MAX_FACE_COUNT);
            std::random_shuffle(std::begin(cardDeck),std::end(cardDeck));
            displayDeck(cardDeck);
        }
};