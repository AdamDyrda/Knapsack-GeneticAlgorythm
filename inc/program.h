/**
 *@file program.h
 *@brief Header file for the program functions
 */

#ifndef PROGRAM_H
#define PROGRAM_H
#include <iostream>
#include <vector>

#include "userInput.h"
#include "constants.h"
#include "../inc/utilities.h"
#include "../inc/geneticAlgorythm.h"
#include "../inc/item.h"


namespace program {

    /**
     * @brief function that runs the program
     * @param userInput user input structure
     */
    void runProgram(const UserInput &userInput);

    /**
     * @brief function that runs the genetic algorithm loop
     * @param userInput user input structure
     * @param items vector of available items
     * @param outVector vector of chromosomes
     * @param generationCounter counter of the generation
     * @return vector of chromosomes
     */
    std::vector<Chromosome>geneticLoop(const UserInput &userInput, const std::vector<Item> &items, const std::vector<Chromosome> &outVector,size_t &generationCounter);
}
#endif //PROGRAM_H
