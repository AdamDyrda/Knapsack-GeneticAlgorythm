
/**
 * @file main.cpp
 * @brief Main file of the project
 * @details This file contains the main function of the project. It reads user input and runs the program function.
 */

#include "inc/utilities.h"
#include "inc/program.h"
#include "inc/userInput.h"




int main(int argc, char *argv[]) {

    UserInput userInput = utilities::parseUserInput(argc, argv);
    program::runProgram(userInput);
    return 0;


}
