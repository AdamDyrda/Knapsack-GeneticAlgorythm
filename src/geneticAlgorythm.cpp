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
#include "../inc/chromosome.h"
#include "../inc/userInput.h"
#include "../inc/utilities.h"

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

std::vector<Chromosome> create_population(const size_t populationSize, const size_t numberOfItems) {
    std::vector<Chromosome> population;
    for (int i = 0; i < populationSize; i++) {
        std::string genome = create_chromosome(numberOfItems);

        population.push_back(Chromosome{genome, 0});
    }
    return population;
}

std::vector<Chromosome> fitness_function(const std::vector<Chromosome> &population, const std::vector<Item> &items,
                                         const float knapsackCapacity) {
    std::vector<Chromosome> results_vector;

    for (const auto &i: population) {
        float totalWeight = 0;
        float totalValue = 0;
        for (int j = 0; j < i.chromosome.size(); j++) {
            if (i.chromosome[j] == '1') {
                totalWeight += items[j].weight;
                totalValue += items[j].value;
            }
        }
        if (totalWeight <= knapsackCapacity) {
            results_vector.push_back(Chromosome{i.chromosome, totalValue});
        } else {
            results_vector.push_back(Chromosome{i.chromosome, 0});
        }
        std::sort(results_vector.begin(), results_vector.end(), [](const Chromosome &a,const Chromosome &b) {
            return a.fitnessScore > b.fitnessScore;
        });
    }
    return results_vector;
}


std::vector<Chromosome> selection(const std::vector<Chromosome> &population) {
    std::vector<Chromosome> sortedPopulation = population;
    utilities::populationSort(sortedPopulation);

     if (sortedPopulation[0].fitnessScore==0) {
     return population;
    }else
    {
        std::vector<Chromosome> parents;
        for (auto &i: population) {
            if (i.fitnessScore >= 0.85 * population[0].fitnessScore) {
                parents.push_back(i);
            }
        }
        if (parents.size() < population.size() * 0.15) {
            int i=parents.size()-1;
            while (parents.size() < population.size() * 0.15) {
                parents.push_back(sortedPopulation[i++]);
            }
        }
        return parents;
    }
}


    std::vector<Chromosome> crossover(const std::vector<Chromosome> &parents, const size_t numberOfOffspring){
        std::vector<Chromosome> offspring;

    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<> distrib(0,parents.size()-1);


    std::vector<Chromosome>sortedParents = parents;
    utilities::populationSort(sortedParents);
        offspring.push_back(sortedParents[0]);
        while (offspring.size() < numberOfOffspring) {
            Chromosome parent1 = parents[distrib(gen)];
            Chromosome parent2 = parents[distrib(gen)];
            std::string child;

            for (int j = 0; j < parents[0].chromosome.size(); j++) {
                if (random_genome() == 0) {
                    child += parent1.chromosome[j];
                } else {
                    child += parent2.chromosome[j];
                }
            }
                offspring.push_back(Chromosome{child, 0});
        }
        return offspring;
    }
}

