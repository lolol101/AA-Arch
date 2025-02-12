#include "AhoCorasick.hpp"

#include <unordered_map>

namespace algo::util::ahocorasick {
    BorTreeNode::BorTreeNode() :
            parent(0), suffLink(-1), parentChar(-1), isTerminal(false), deep(0), stringNum(-1) {}
    BorTreeNode::BorTreeNode(int parent_, char parentChar_) :
            parent(parent_), suffLink(-1), parentChar(parentChar_), isTerminal(false), deep(0), stringNum(-1) {}

    /// @brief Allows to move around nodes of the Bor (tree).
    /// @param cur index of the current node in container in argument "vertexes".
    /// @param letter char symbol which represents edge name to move to the next state.
    /// @param vertexes container where the Bor (tree) is located.
    int moveToNextState(int cur, int letter, std::vector<BorTreeNode>& vertexes) { 
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
    int getSuffLink(int cur, std::vector<BorTreeNode>& vertexes) {
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
        if (pattern != "") {
            int cur = 0;
            int deep = 0;
            for (int i = 0; i < pattern.size(); ++i, ++deep) {
                int letter = pattern[i];
                if (vertexes[cur].childs.find(letter) == vertexes[cur].childs.end()) {
                    vertexes.emplace_back(cur, letter);
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
    /// @param dictStrings distinct strings that are needed to be found in "text".
    /// @param vertexes container where the Bor (tree) is located.
    std::vector<std::vector<size_t>> findAllStringsAhoCorasick(const std::string& text, const std::set<std::string>& patterns) {
        using namespace algo::util::ahocorasick;
        
        int cur = 0;
        std::vector<std::vector<size_t>> occurences(patterns.size(), std::vector<size_t>());
        std::vector<BorTreeNode> vertexes;
        vertexes.emplace_back();

        {
            int i = 0;
            for (auto it = patterns.begin(); it != patterns.end(); ++it, ++i)
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
