#include "algorithm.hpp"

#include <unordered_map>
#include <iostream>

namespace {
    struct Node {
        std::unordered_map<int, int> childs;
        std::unordered_map<int, int> nextEdgeStates;
        int parent;
        int suffLink;
        char parentChar;
        bool isTerminal;
        int stringNum;
    };

    int getSuffLink(int cur, std::vector<Node> &vertexes);

    int changeState(int cur, int letter, std::vector<Node> &vertexes) {
        if (vertexes[cur].nextEdgeStates.find(letter) == vertexes[cur].nextEdgeStates.end()) {
            if (vertexes[cur].childs.find(letter) != vertexes[cur].childs.end())
                vertexes[cur].nextEdgeStates[letter] = vertexes[cur].childs[letter];
            else if (cur == 0)
                vertexes[cur].nextEdgeStates[letter] = 0;
            else 
                vertexes[cur].nextEdgeStates[letter] = changeState(getSuffLink(cur, vertexes), letter, vertexes);
        }
        return vertexes[cur].nextEdgeStates[letter];
    }

    int getSuffLink(int cur, std::vector<Node> &vertexes) {
        if (vertexes[cur].suffLink == -1) {
            if (cur == 0 || vertexes[cur].parent == 0)
                vertexes[cur].suffLink = 0;
            else
                vertexes[cur].suffLink = changeState(getSuffLink(vertexes[cur].parent, vertexes), vertexes[cur].parentChar, vertexes); 
        }
        return vertexes[cur].suffLink;
    }

    void addString(const std::string &str, int index, std::vector<Node>& vertexes) {
        if (str != "") {
            int cur = 0;
            for (int i = 0; i < str.size(); ++i) {
                int letter = str[i];
                if (vertexes[cur].childs.find(letter) == vertexes[cur].childs.end()) {
                    vertexes.emplace_back();
                    vertexes.back().suffLink = -1;
                    vertexes.back().parent = cur;
                    vertexes.back().parentChar = letter;
                    vertexes.back().isTerminal = false;
                    vertexes[cur].childs[letter] = vertexes.size() - 1;
                }
                cur = vertexes[cur].childs[letter];
            }
            vertexes[cur].isTerminal = true;
            vertexes[cur].stringNum = index;
        }
    }
} 

namespace algo {
    std::vector<std::vector<size_t>> findAllStringsAhoCorasick(const std::string &text, const std::vector<std::string>& patterns) {
        int cur = 0;
        std::vector<std::vector<size_t>> occurences(patterns.size(), std::vector<size_t>());
        std::vector<Node> vertexes(1);
        for (int i = 0; i < patterns.size(); ++i)
            addString(patterns[i], i, vertexes);
        for (int i = 0; i < text.size(); ++i) {
            char letter = text[i];
            cur = changeState(cur, letter, vertexes);
            if (vertexes[cur].isTerminal) {
                occurences[vertexes[cur].stringNum].emplace_back(i - patterns[vertexes[cur].stringNum].size() + 1);
            }
        }
        return occurences;
    }
}
