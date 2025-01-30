/**
 * @file geneticAlgorythm.h
 * @brief Header file for the genetic algorithm functions
 */
#ifndef GENETICALGORYTHM_H
#define GENETICALGORYTHM_H
#include <iostream>
#include <string>
#include <vector>
#include "item.h"
#include "individual.h"

namespace genetic {
/**
 * @brief function that generates a random genome
 * @return 0 or 1
 */
int random_genome();

/**
 * @brief function that creates a population of chromosomes
 * @param population vector containing the population
 * @param populationSize size of the population
 * @param numberOfItems number of items in the knapsack
 * @return vector of individuals
 */
void create_population(std::vector<Individual> &population, size_t populationSize, size_t numberOfItems);

/**
 *
 * @param numberOfItems number of available items
 * @return a string of 0s and 1s representing the chromosome with length equal to the number of available items
 */
std::string create_chromosome(size_t numberOfItems);

/**
    * @brief function that calculates the fitness of the chromosomes
    * @param population vector of chromosomes in the population
    * @param items vector of available items
    * @param knapsackCapacity capacity of the knapsack
    * @return vector of chromosomes with calculated fitness score
    */
void fitness_function(std::vector<Individual> &population, std::vector<Item> const &items,
                      float knapsackCapacity);

/**
 * @brief function that selects the parents for crossover
 * @param population vector of chromosomes in the population
 * @return chromosomes selected to be parents in crossover
 */
void selection(std::vector<Individual> &population);

/**
 * @brief function that performs the crossover
 * @param parents vector of chromosomes selected to be parents
 * @param numberOfOffspring number of offspring to be created
 * @return vector of offspring
 */

void crossover(std::vector<Individual> &parents, size_t numberOfOffspring);
}
#endif //GENETICALGORYTHM_H
