/**
* @file geneticAlgorythm.cpp
* @brief Implementation of the genetic algorithm functions
*/

#include "../inc/geneticAlgorythm.h"

#include <algorithm>
#include <iostream>
#include <string>
#include <vector>
#include <random>

#include "../inc/Item.h"
#include "../inc/individual.h"

struct Item;

namespace genetic {
int random_genome() {
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<> distrib(0, 1);

    return distrib(gen) % 2;
}

std::string create_chromosome(size_t numberOfItems) {
    std::string startingChromosome;
    for (int i = 0; i < numberOfItems; i++) {
        startingChromosome += std::to_string(random_genome());
    }
    return startingChromosome;
}

void create_population(std::vector<Individual> &population, size_t const populationSize, size_t const numberOfItems) {
    for (int i = 0; i < populationSize; i++) {
        std::string genome = create_chromosome(numberOfItems);

        population.push_back(Individual{genome, 0, 0, 0});
    }
}

void fitness_function(std::vector<Individual> &population, std::vector<Item> const &items,
                      float const knapsackCapacity) {
    for (auto &individual: population) {
        float totalWeight = 0;
        float totalValue = 0;
        for (int j = 0; j < individual.chromosome.size(); j++) {
            if (individual.chromosome[j] == '1') {
                totalWeight += items[j].weight;
                totalValue += items[j].value;
            }
        }
        if (totalWeight <= knapsackCapacity) {
            individual.fitnessScore = totalValue;
            individual.value = totalValue;
            individual.weight = totalWeight;
        } else {
            individual.fitnessScore = 0;
            individual.value = totalValue;
            individual.weight = totalWeight;
        }
    }
    std::sort(population.begin(), population.end(), [](Individual const &a, Individual const &b) {
        return a.fitnessScore > b.fitnessScore;
    });
}


void selection(std::vector<Individual> &population) {
    std::vector<Individual> sortedPopulation = population;

    if (sortedPopulation[0].fitnessScore == 0) {
        return;
    } else {
        std::vector<Individual> parents;
        for (auto &i: population) {
            if (i.fitnessScore >= 0.85 * population[0].fitnessScore) {
                parents.push_back(i);
            }
        }
        if (parents.size() < population.size() * 0.15) {
            int i = parents.size() - 1;
            while (parents.size() < population.size() * 0.15) {
                parents.push_back(sortedPopulation[i++]);
            }
        }
        population = parents;
    }
}


void crossover(std::vector<Individual> &parents, size_t const numberOfOffspring) {
    std::vector<Individual> offspring;

    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<> distrib(0, parents.size() - 1);

    offspring.push_back(parents[0]);
    while (offspring.size() < numberOfOffspring) {
        Individual const &parent1 = parents[distrib(gen)];
        Individual const &parent2 = parents[distrib(gen)];
        std::string child;

        for (int j = 0; j < parents[0].chromosome.size(); j++) {
            if (random_genome() == 0) {
                child += parent1.chromosome[j];
            } else {
                child += parent2.chromosome[j];
            }
        }
        offspring.push_back(Individual{child, 0});
    }
    parents = offspring;
}
}
