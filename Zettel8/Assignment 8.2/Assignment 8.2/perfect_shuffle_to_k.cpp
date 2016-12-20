#include <cassert>
#include <iostream>
#include <string>
#include <vector>

template<typename T>
void printVectors(std::vector<T> printV) {	
    for (auto i : printV) {						
        std::cout << i << ", ";
    }											
    std::cout << "\b\b " << std::endl;
}

std::vector<int> init_deck() {              
    std::vector<int> deck;                  
    for (int i = 0; i < 52; ++i) {          
        deck.push_back(i);
    }
    return deck;
}

std::vector<int> shuffle(std::vector<int> cards, bool out) { 
    std::vector<int> new_deck;
    int counter = 0;
    int maxI = cards.size();
    if (out) { 
        for (int i = 0; i < maxI; ++i) {
            if (i % 2 == 0) {
                new_deck.push_back(cards[counter]);
            }
            else {
                new_deck.push_back(cards[counter + (maxI / 2)]);
                ++counter;
            }
        }
    }
    else {
        for (int i = 0; i < maxI; ++i) {
            if (i % 2 != 0) {
                new_deck.push_back(cards[counter]);
                ++counter;
            }
            else {
                new_deck.push_back(cards[counter + (maxI / 2)]);
            }
        }
    }
    return new_deck;
}                                                               // taking the functions from the previous assignment

std::vector<int> shuffle_top_to(std::vector<int> deck, uint8_t k) {
    for (int i = 7; i > 0; --i) {           // iterating through the number 7 times. The reason for that is
        k = k << 1;                         // the number can only have 8 bits. The first few bits will never
        deck = shuffle(deck, !(k >= 128));  // have a 1 seeing as the highest number can only be 52 and 2 to the power
    }                                       // of 8 = 128
                                            // made the bool equal to if k is greater-equal than 128
    return deck;
}

inline void wait_on_enter()                 // started using visual studio which terminates the terminal after the program
{                                           // finished running
    std::string dummy;
    std::cout << "Enter to continue..." << std::endl;
    std::getline(std::cin, dummy);
}

int main() {
    std::vector<int> deck = init_deck();
    std::vector<int> counting = init_deck();     // creating a vector for a nicer output, works for smaller card decks
    //std::vector<int> counter;
    for (int i = 0; i < deck.size(); ++i) {     // iterating through every possibility from 0 to the max deck size to 
        std::vector<int> deck2 = init_deck();   // ensure that the program works for every possibility
        deck2 = shuffle_top_to(deck2, i);
        /*if (deck2[i] != 0) {
            counter.push_back(i);               // prefer this method of testing for which numbers it wont work
        }*/
        assert(deck2[i] == 0);
    }
    //printVectors(counter);                    // this would tell you for which not work
    
    deck = shuffle_top_to(deck, 2);             // manual check
    printVectors(counting);
    printVectors(deck);
    
    wait_on_enter();
}