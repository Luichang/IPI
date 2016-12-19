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
}

std::vector<int> shuffle_top_to(std::vector<int> deck, uint8_t k) {
    //std::vector<int> outVector;
    uint8_t kCopy = k;
    auto start = 0;
    while (!(kCopy & 1)) {
        kCopy >>= 1;
        std::cout << ++start << std::endl;
    }
    while (kCopy != 0)
    {
        if (kCopy & 1)
        {
            deck = shuffle(deck, false);
        }
        else {
            deck = shuffle(deck, true);
        }
        kCopy >>= 1;
    }
    while (start != 0) {
        deck = shuffle(deck, true);
        --start;
    }
    //bool hadFirstZero = !(kCopy & 1);
    //std::cout << hadFirstZero << std::endl;
    /*for (int t = 0; t < 8; ++t) {
        if (kCopy & 1) {
            deck = shuffle(deck, false);
        }
        else {
            deck = shuffle(deck, true);
        }
        kCopy >>= 1;
    }
    while (k != 0)
    {
        if (k & 1)
        {
            deck = shuffle(deck, false);
        }
        else {
            deck = shuffle(deck, true);
        }
        k >>= 1;
    }*/
    /*if (hadFirstZero) {
        deck = shuffle(deck, true);
        hadFirstZero = false;
    }*/
    std::cout << std::endl;
    return deck;
}

inline void wait_on_enter()
{
    std::string dummy;
    std::cout << "Enter to continue..." << std::endl;
    std::getline(std::cin, dummy);
}

int main() {
    std::vector<int> deck1 = init_deck();
    
    std::vector<int> deck = init_deck();
    std::vector<int> counting(deck1.size());
    for (int i = 0; i < counting.size(); ++i) {
        counting[i] = i;
    }
    std::vector<int> counter;
    for (int i = 1; i < deck1.size(); ++i) {
        std::vector<int> deck2 = init_deck(); 
        deck2 = shuffle_top_to(deck2, i);
        if (deck2[i] != 0) {
            counter.push_back(i);
        }
    }

    printVectors(counter);
    
    /*deck1 = shuffle_top_to(deck1, 5);
    printVectors(counting);
    printVectors(deck1);*/
    
    wait_on_enter();
}