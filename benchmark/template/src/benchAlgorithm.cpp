#define CATCH_CONFIG_RUNNER

#include <benchAlgorithm.hpp>

void benchmark::singlepattern::benchSinglePatternAlgo(
    AlgoFuncType1 findString, 
    const std::string& alphabet,
    unsigned textSize,
    unsigned patternSize)
{
    std::string text = util::generateStringFromAlphabet(textSize, alphabet);
    std::string pattern = util::generateStringFromAlphabet(patternSize, alphabet);
    
    BENCHMARK("findString") {
        findString(text, pattern);
    };
}

void benchmark::multipattern::benchMultiPatternAlgo(
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

    BENCHMARK("findAllStrings") {
        findAllStrings(text, patterns);
    };
}
