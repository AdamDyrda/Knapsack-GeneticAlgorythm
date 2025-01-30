
/**
 * @file userInput.h
 * @brief Header file for the UserInput structure
 */
#ifndef FinalProject_USERINPUT_H
#define FinalProject_USERINPUT_H
#include <string>



/**
*@brief structure representing user input for the program
*/
struct UserInput {
    std::string inputFileName;
    std::string outputFileName;
    int populationSize{};
    float knapsackCapacity{};
    int numberOfGenerations{};
    bool showHelpMessage{};
};

#endif
