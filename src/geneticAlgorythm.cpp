#include <iostream>
#include <string>
namespace genetic {

int random_binary() {
    return rand() % 2;
}
std::string create_genome(int numberOfItems) {
    std::string startingGenome;
    for (int i=0; i<numberOfItems; i++) {
        startingGenome += std::to_string(rand() % 2);
    }
    return startingGenome;
}

void create_population(const int &populationSize, int numberOfItems) {
    for (int i=0; i<populationSize; i++) {
        std::string genome = create_genome(numberOfItems);
        std::cout << genome << std::endl;
        }
    }
}



