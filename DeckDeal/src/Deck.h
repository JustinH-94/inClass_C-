#include <vector>
#include <string>
class Deck{
    public:
        enum Face {A, two, three, four, five, six, seven, eight, nine, ten, J, Q, K };
        enum Suit {S, H, C, D};

        struct Card{
            Face face;
            Suit suit;
            int numSuits = 4;
            int numFaces = 13;
        };

        struct CardDeck{
            std:: vector<Card> cards;
            std:: string card;
            int mainDeckSize = 52;
        };

        int euchreDeckSize = 24;

        void createDeck(){
            CardDeck deck;
            for(int i = 0; i < deck.mainDeckSize; i++){
                Card card;
                for(int j = 0; j < card.numSuits; j++){
                    for(int x = 0; j < card.numFaces; x++){
                        card.suit = Suit(j);
                        card.face = Face(x);
                        deck.cards.push_back(card);
                    }
                }
            }
        }

};