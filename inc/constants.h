
/**
 * @file constatns.h
 * @brief header file containg the constants used in the program
 */

#ifndef CONSTANTS_H
#define CONSTANTS_H
#include <string_view>

namespace Constants {
    constexpr std::string_view inputFileSwitch = "-i";
    constexpr std::string_view outputFileSwitch = "-o";
    constexpr std::string_view knapsackCapacitySwitch = "-c";
    constexpr std::string_view generationsSwitch = "-g";
    constexpr std::string_view populationSwitch = "-n";

    /**
     * @brief help message displayed when the program is run without any arguments
     */
    constexpr std::string_view helpMessage = "The program is run in a command line with the switches:\n"
            "Usage: ./main [options]\n"
            "\n"
            "-i input file with a set of items\n"
            "-o output file with the best solutions in all generations\n"
            "-c knapsack capacity\n"
            "-g number of generations\n"
            "-n number of individuals in a generation";

}
#endif //CONSTANTS_H
