#include <benchAlgorithm.hpp>

void benchmark::runSinglePatternAlgo(
    AlgoFuncType1 findString, 
    const std::string& alphabet,
    unsigned textSize,
    unsigned patternSize)
{
    std::string text = util::generateStringFromAlphabet(textSize, alphabet);
    std::string pattern = util::generateStringFromAlphabet(patternSize, alphabet);
    
    findString(text, pattern);
}

void benchmark::runMultiPatternAlgo(
    AlgoFuncType2 findAllStrings, 
    const std::string& alphabet,
    unsigned textSize,
    unsigned patternSize,
    unsigned patternCount    
)
{
    std::string text = util::generateStringFromAlphabet(textSize, alphabet);
    std::set<std::string> patterns;

    for (size_t i = 0; i < patternCount; i++)
        patterns.insert(util::generateStringFromAlphabet(patternSize, alphabet));

    findAllStrings(text, patterns);
}
