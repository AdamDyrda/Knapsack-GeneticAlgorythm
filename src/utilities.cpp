/**
* @file utilities.cpp
* @brief Implementation of the utilities functions
*/

#include "../inc/utilities.h"

#include <algorithm>

#include "../inc/constants.h"
#include <iostream>
#include <fstream>
#include <sstream>


#include "../inc/chromosome.h"

namespace utilities {
UserInput parseUserInput(int argc, char *argv[]) {
    UserInput userInput{};
    if (argc == 1) {
        userInput.showHelpMessage = true;
        return userInput;
    }
    for (int i = 1; i < argc; i++) {
        std::string arg = argv[i];
        if (arg == Constants::inputFileSwitch) {
            userInput.filePaths.inputFileName = argv[++i];
        } else if (arg == Constants::outputFileSwitch) {
            userInput.filePaths.outputFileName = argv[++i];
        } else if (arg == Constants::knapsackCapacitySwitch) {
            userInput.knapsackCapacity = strtof(argv[++i], nullptr);
        } else if (arg == Constants::generationsSwitch) {
            userInput.numberOfGenerations = static_cast<int>(strtol(argv[++i], nullptr, 10));
        } else if (arg == Constants::populationSwitch) {
            userInput.populationSize = static_cast<int>(strtol(argv[++i], nullptr, 10));
        }
    }
    return userInput;
}

bool validateUserInput(const UserInput &userInput) {
    if (userInput.filePaths.inputFileName.empty() || userInput.filePaths.outputFileName.empty() ||
        userInput.knapsackCapacity == 0 || userInput.numberOfGenerations == 0 || userInput.populationSize == 0) {
        return false;
        }
    return true;
}

void parseItems(const std::string &fileName, std::vector<Item> &items) {
    std::ifstream file(fileName);
    if (!file.is_open()) {
        throw std::runtime_error("Error opening file");
    }
    std::string line;
    while (std::getline(file, line)) {
        std::istringstream iss(line);
        std::string itemName;
        float itemWeight;
        int itemValue;

        if (iss >> itemName >> itemWeight >> itemValue) {
            items.emplace_back(itemName, itemWeight, itemValue);
        } else {
            std::cerr << "Invalid line format: " << line << std::endl;
        }
    }
    file.close();
}

//FOR DEBUG PURPOSES ONLY REMOVE BEFORE SUBMISSION
void printGeneration(const std::vector<Chromosome> &population, const size_t &generationCounter) {
    std::cout << "Generation: " << generationCounter << std::endl;
    for (const auto &i: population) {
        std::cout << i.chromosome << " " << i.fitnessScore << std::endl;
    }
}

void clearOutputFile(const std::string &path) {
    std::ofstream output;
    output.open(path);
    if (!output.is_open()) {
        std::cerr << "Error opening output file " << path << '\n';
        return;
    }
    output.close();
}
void populationSort(std::vector<Chromosome> &population) {
    std::sort(population.begin(), population.end(), [](const Chromosome &a, const Chromosome &b) {
        return a.fitnessScore > b.fitnessScore;
    });
}

void saveToFile(const std::string &path,const std::vector<Chromosome> &results_vector, const size_t &generationCounter,
                const std::vector<Item> &items,const UserInput &userInput) {
    std::ofstream output;
    output.open(path, std::ios::app);
    if (!output.is_open()) {
        std::cerr << "Error opening output file " << path << '\n';
        return;
    }
    std::vector<Chromosome>sortedPopulation = results_vector;
    populationSort(sortedPopulation);

    const Chromosome &theBestChromosome = sortedPopulation[0];
    float weight = 0;
    float value = 0;
    if (theBestChromosome.fitnessScore!=0) {
    for (int i = 0; i < theBestChromosome.chromosome.size(); i++) {
        if (theBestChromosome.chromosome[i] == '1') {
            weight += items[i].weight;
            value += items[i].value;
        }
    }
    }
    output << "Generation " << generationCounter << ',' << "weight: " << weight << ',' << "value: " << value <<std::endl;
    if (generationCounter == userInput.numberOfGenerations) {
        for (int i = 0; i < theBestChromosome.chromosome.size(); i++) {
            if (theBestChromosome.chromosome[i] == '1') {
                const auto &[name, weight, value] = items[i];
                output << name << " " << weight << " " << value << std::endl;
            }
        }
        output.close();
    }
}
}
