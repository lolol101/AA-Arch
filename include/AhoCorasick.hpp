#pragma once

#include <set>
#include <string>
#include <vector>
#include <unordered_map>

namespace algo::util::ahocorasick {
    struct BorTreeNode {
        std::unordered_map<int, int> childs;
        std::unordered_map<int, int> nextEdgeStates;
        int parent;
        int suffLink;
        char parentChar;
        bool isTerminal;
        int deep;
        int stringNum;

        BorTreeNode();
            
        BorTreeNode(int parent_, char parentChar_);
    };

    int getSuffLink(int cur, std::vector<BorTreeNode>& vertexes);

    int moveToNextState(int cur, int letter, std::vector<BorTreeNode>& vertexes);

    int getSuffLink(int cur, std::vector<BorTreeNode>& vertexes);

    void addString(const std::string &pattern, int index, std::vector<BorTreeNode>& vertexes);
}

namespace algo {
    std::vector<std::vector<size_t>> findAllStringsAhoCorasick(const std::string &text, const std::set<std::string>& patterns);
}