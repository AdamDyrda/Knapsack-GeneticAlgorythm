#include <iostream>




int main(int argc, char *argv[])
{
    std::string inputFileName;
    std::string outputFileName;
    float capacity;
    int numberOfGenerations;
    int numberOfIndividuals;
for (int i = 1; i < argc; i++) {
    std::string arg = argv[i];
    if(arg=="-i") {inputFileName = argv[++i];}
    else if(arg=="-o") {outputFileName = argv[++i];}
    else if(arg=="-c"){capacity = atof(argv[++i]);}
    else if(arg=="-g"){numberOfGenerations = atoi(argv[++i]);}
    else if(arg=="-n"){numberOfIndividuals = atoi(argv[++i]);}
}
    return 0;
}
