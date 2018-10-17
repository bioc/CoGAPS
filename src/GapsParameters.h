#ifndef __COGAPS_GAPS_PARAMETERS_H__
#define __COGAPS_GAPS_PARAMETERS_H__

#include "data_structures/Matrix.h"
#include "file_parser/FileParser.h"

#include <vector>
#include <string>

struct GapsParameters
{
public:

    template <class DataType>
    GapsParameters(const DataType &data);

    void peekCheckpoint(const std::string &file);

    Matrix fixedMatrix;

    std::vector<unsigned> dataIndicesSubset;

    std::string checkpointFile;
    std::string checkpointOutFile;

    uint32_t seed;

    unsigned nGenes;
    unsigned nSamples;
    unsigned nPatterns;
    unsigned nIterations;
    unsigned maxThreads;
    unsigned outputFrequency;
    unsigned checkpointInterval;

    float alphaA;
    float alphaP;
    float maxGibbsMassA;
    float maxGibbsMassP;

    bool useFixedMatrix;
    bool subsetData;
    bool useCheckPoint;
    bool transposeData;
    bool singleCell;
    bool printMessages;
    bool subsetGenes;
    bool printThreadUsage;
    bool useSparseOptimization;

    char whichFixedMatrix;

private:

    void calculateDataDimensions(const std::string &file);
    void calculateDataDimensions(const Matrix &mat);
};

template <class DataType>
GapsParameters::GapsParameters(const DataType &data)
    :
fixedMatrix(Matrix()),
dataIndicesSubset(std::vector<unsigned>()),
checkpointFile(std::string()),
checkpointOutFile("gaps_checkpoint.out"),
seed(0),
nGenes(0),
nSamples(0),
nPatterns(3),
nIterations(1000),
maxThreads(1),
outputFrequency(500),
checkpointInterval(250),
alphaA(0.01f),
alphaP(0.01f),
maxGibbsMassA(100.f),
maxGibbsMassP(100.f),
useFixedMatrix(false),
subsetData(false),
useCheckPoint(false),
transposeData(false),
singleCell(false),
printMessages(true),
subsetGenes(false),
printThreadUsage(true),
useSparseOptimization(false),
whichFixedMatrix('N')
{
    calculateDataDimensions(data);
}

#endif