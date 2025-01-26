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

    void runProgram(const UserInput &userInput);

    std::vector<Chromosome>geneticLoop(const UserInput &userInput, const std::vector<Item> &items, const std::vector<Chromosome> &outVector,size_t &generationCounter);
}
#endif //PROGRAM_H
