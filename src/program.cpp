/**
 *@file program.cpp
 *@brief implementation of the program functions
 */

#include <iostream>
#include <vector>

#include "../inc/constants.h"
#include "../inc/userInput.h"
#include "../inc/utilities.h"
#include "../inc/geneticAlgorythm.h"
#include "../inc/item.h"
#include "../inc/program.h"

namespace program {
    void runProgram(const UserInput &userInput) {
        size_t generationCounter = 1;
        std::vector<Item> items;
        //
        if (userInput.showHelpMessage) {
            std::cout<<Constants::helpMessage;
            return;
        }
        if (!utilities::validateUserInput(userInput)) {
            std::cout<<"Provided input is invalid. Please provide all the necessary arguments";
            return;
        }
        utilities::clearOutputFile(userInput.filePaths.outputFileName);

        utilities::parseItems(userInput.filePaths.inputFileName, items);

        std::vector<Chromosome>outVector = genetic::create_population(userInput.populationSize, items.size());
        geneticLoop(userInput, items, outVector,generationCounter);



    }

    std::vector<Chromosome>geneticLoop(const UserInput &userInput, const std::vector<Item> &items, const std::vector<Chromosome> &outVector, size_t &generationCounter) {
        std::vector<Chromosome>population = outVector;
        for (int i = 0; i < userInput.numberOfGenerations; i++) {
            population = genetic::fitness_function(population, items, userInput.knapsackCapacity);
            utilities::saveToFile(userInput.filePaths.outputFileName, population, generationCounter, items, userInput);
            population = genetic::selection(population);
            population = genetic::crossover(population, userInput.populationSize);
            std::cout<<generationCounter/(float)userInput.numberOfGenerations*100<<"% completed"<<std::endl;
            generationCounter++;


        }
        std::cout<<"check output file for results!"<<std::endl;
        return population;
    }

}
