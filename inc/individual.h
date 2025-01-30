
/**
 * @file genome.h
 * @brief Header file for the Chromosome struct
 */

#ifndef GENOME_H
#define GENOME_H
#include <string>

struct Individual {
    std::string chromosome;
    float fitnessScore;
    float weight;
    float value;
};
#endif //GENOME_H
