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
    void geneticLoop(UserInput const &userInput, std::vector<Item> const &items,std::vector<Individual> &population, size_t &generationCounter) {
        for (int i = 0; i < userInput.numberOfGenerations; i++) {
            genetic::fitness_function(population, items, userInput.knapsackCapacity);
            utilities::printGeneration(population, generationCounter);
            utilities::saveToFile(userInput.outputFileName, population, generationCounter, items, userInput);
            genetic::selection(population);
            genetic::crossover(population, userInput.populationSize);
            std::cout<<generationCounter/static_cast<float>(userInput.numberOfGenerations)*100<<"% completed"<<std::endl;
            generationCounter++;


        }
        std::cout<<"check output file for results!"<<std::endl;
    }

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
        utilities::clearOutputFile(userInput.outputFileName);

        utilities::parseItems(userInput.inputFileName, items);
        std::vector<Individual>population;
        genetic::create_population(population,userInput.populationSize, items.size());
        geneticLoop(userInput, items, population,generationCounter);



    }

}
