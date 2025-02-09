#include "algorithm.hpp"

#include <unordered_map>

namespace { // unnamed namespace for hiding functions implementing algorithm 
    struct BorTreeNode {
        std::unordered_map<int, int> childs;
        std::unordered_map<int, int> nextEdgeStates;
        int parent;
        int suffLink;
        char parentChar;
        bool isTerminal;
        int deep;
        int stringNum;

        BorTreeNode(int parent_, int suffLink, char parentChar_, bool isTerminal_, int deep_=-1, int stringNum_=-1) :
            parent(parent_), suffLink(suffLink), parentChar(parentChar_), isTerminal(isTerminal_), deep(deep_), stringNum(stringNum_) {} 
    };

    int getSuffLink(int cur, std::vector<BorTreeNode> &vertexes);

    /// @brief Allows to move around nodes of the Bor (tree).
    /// @param cur index of the current node in container in argument "vertexes".
    /// @param letter char symbol which represents edge name to move to the next state.
    /// @param vertexes container where the Bor (tree) is located.
    int moveToNextState(int cur, int letter, std::vector<BorTreeNode> &vertexes) { 
        if (vertexes[cur].nextEdgeStates.find(letter) == vertexes[cur].nextEdgeStates.end()) {
            if (vertexes[cur].childs.find(letter) != vertexes[cur].childs.end())
                vertexes[cur].nextEdgeStates[letter] = vertexes[cur].childs[letter];
            else if (cur == 0)
                vertexes[cur].nextEdgeStates[letter] = 0;
            else 
                vertexes[cur].nextEdgeStates[letter] = moveToNextState(getSuffLink(cur, vertexes), letter, vertexes);
        }
        return vertexes[cur].nextEdgeStates[letter];
    }

    /// @brief Calculates index of node representing the longest suffix of current string.
    /// @param cur index of the current node in container in argument "vertexes".
    /// @param vertexes container where the Bor (tree) is located.
    /// @note The function works in a lazy manner so the first call has a non-constant time complexity.
    int getSuffLink(int cur, std::vector<BorTreeNode> &vertexes) {
        if (vertexes[cur].suffLink == -1) {
            if (cur == 0 || vertexes[cur].parent == 0)
                vertexes[cur].suffLink = 0;
            else
                vertexes[cur].suffLink = moveToNextState(getSuffLink(vertexes[cur].parent, vertexes), vertexes[cur].parentChar, vertexes); 
        }
        return vertexes[cur].suffLink;
    }

    /// @brief Adds string from dictonary into the Bor (tree) structure.
    /// @param pattern a string from dictionary.
    /// @param index number of a string in dictionary.
    /// @param vertexes container where the Bor (tree) is located.
    /// @note Only "addString" function is designed to change "deep" and "stringNum" variable values.
    void addString(const std::string &pattern, int index, std::vector<BorTreeNode>& vertexes) {
        if (dictStrings != "") {
            int cur = 0;
            int deep = 0;
            for (int i = 0; i < dictStrings.size(); ++i, ++deep) {
                int letter = dictStrings[i];
                if (vertexes[cur].childs.find(letter) == vertexes[cur].childs.end()) {
                    vertexes.emplace_back(cur, -1, letter, false, -1, -1);
                    vertexes[cur].childs[letter] = vertexes.size() - 1;
                }
                cur = vertexes[cur].childs[letter];
            }
            vertexes[cur].isTerminal = true;
            vertexes[cur].deep = deep;
            vertexes[cur].stringNum = index;
        }
    }
} 

namespace algo {

    /// @brief Searches for all occurrences of strings from "dictStrings" in "text" 
    /// @brief and returns the indexes of those occurrences relative to the order of the dictionary.
    /// @param text a string wich contains text.
    /// @param dictStrings  distinct strings that are needed to be found in "text".
    /// @param vertexes container where the Bor (tree) is located.
    std::vector<std::vector<size_t>> findAllStringsAhoCorasick(const std::string &text, const std::set<std::string>& dictStrings) {
        int cur = 0;
        std::vector<std::vector<size_t>> occurences(dictStrings.size(), std::vector<size_t>());
        std::vector<BorTreeNode> vertexes;
        vertexes.emplace_back(0, -1, -1, false, 0, -1);

        {
            int i = 0;
            for (auto it = dictStrings.begin(); it != dictStrings.end(); ++it, ++i)
                addString(*it, i, vertexes);
        }

        for (int i = 0; i < text.size(); ++i) {
            char letter = text[i];
            cur = moveToNextState(cur, letter, vertexes);
            if (vertexes[cur].isTerminal) {
                int old_cur = cur;
                while (vertexes[cur].isTerminal) {
                    occurences[vertexes[cur].stringNum].emplace_back(i - vertexes[cur].deep + 1);
                    cur = getSuffLink(cur, vertexes);
                }
                cur = old_cur;
            }
        }
        return occurences;
    }
}
