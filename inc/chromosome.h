/**
 * @file genome.h
 * @brief Header file for the Chromosome struct
 */

#ifndef GENOME_H
#define GENOME_H
#include <string>

struct Chromosome {
    std::string chromosome;
    float fitnessScore;
};
#endif //GENOME_H
