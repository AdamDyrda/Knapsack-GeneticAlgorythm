/**
 * @file utilities.h
 * @brief This file contains the declaration of the utilities functions
 */
#ifndef UTILITIES_H
#define UTILITIES_H
#include <vector>

#include "individual.h"
#include "item.h"

#include "userInput.h"

namespace utilities {
    /**
     * @brief Parses the user input
     * @param argc number of arguments
     * @param argv array of arguments
     * @return UserInput structure
     */
    UserInput parseUserInput(int argc, char *argv[]);

    /**
     * @brief functions that parses the items from the file and stores them in a vector
     * @param fileName name of the file to be parsed
     * @param items vector where the items will be stored
     */
    void parseItems(const std::string &fileName, std::vector<Item> &items);


    void printGeneration(const std::vector<Individual> &population, const size_t &generationCounter);
    /**
     * @brief function that validates the user input
     * @param userInput user input structure to be validated
     * @return returns true if the user input is valid, false otherwise
     */
    bool validateUserInput(const UserInput &userInput);

   // int randomNumber(size_t max);
    void populationSort(std::vector<Individual> &population);

    void clearOutputFile(const std::string &path);

    /**
     * @brief function that saves the results to a specified file
     * @param path path to the file
     * @param results_vector vector of items to be saved
     * @param generationCounter specifies the number of generation that is being saved
     * @param items vector of all items
     * @param userInput structure containing the user input
     */

    void saveToFile(std::string const &path,std::vector<Individual> const &results_vector,
                    size_t const &generationCounter, std::vector<Item> const &items, UserInput const &userInput);
}

#endif //UTILITIES_H
