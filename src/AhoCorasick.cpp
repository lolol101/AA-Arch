#include "algorithm.hpp"

namespace {
    const size_t alphabet_size = 32;

    struct Node {
        std::vector<Node*> childs = std::vector<Node*>(alphabet_size, nullptr);
        std::vector<Node*> nextEdgeStates = std::vector<Node*>(alphabet_size, nullptr);
        Node *parent;
        Node *suffLink;
        char parentChar;
        bool isTerminal;
        size_t stringNum;
    };

    Node* getSuffLink(Node *vertex, Node *root);

    Node* changeState(Node *vertex, int letter, Node *root) {
        if (vertex->nextEdgeStates[letter] == nullptr) {
            if (vertex->childs[letter] != nullptr)
                vertex->nextEdgeStates[letter] = vertex->childs[letter];
            else if (vertex == root)
                vertex->nextEdgeStates[letter] = root;
            else 
                vertex->nextEdgeStates[letter] = changeState(getSuffLink(vertex, root), letter, root);
        }
        return vertex->nextEdgeStates[letter];
    }

    Node* getSuffLink(Node *vertex, Node *root) {
        if (vertex->suffLink == nullptr) {
            if (vertex == root || vertex->parent == root)
                vertex->suffLink = root;
            else
                vertex->suffLink = changeState(getSuffLink(vertex, root), vertex->parentChar, root); 
        }
        return vertex->suffLink;
    }

    void addString(const std::string *str, size_t index, Node *root) {
        Node *cur = root;
        root->childs = std::vector<Node*>(alphabet_size, nullptr);
        for (size_t i = 0; i < str->size(); ++i) {
            int letter = (*str)[i] - 'a';
            if (cur->childs[letter] == nullptr) {
                cur->childs[letter] = new Node();
                cur->childs[letter]->suffLink = nullptr;
                cur->childs[letter]->parent = cur;
                cur->childs[letter]->parentChar = letter;
                cur->childs[letter]->isTerminal = false;
            }
            cur = cur->childs[letter];
        }
        cur->isTerminal = true;
        cur->stringNum = index;
    }

    // void deleteTree(Node *root) {
        
    // }
} 

namespace algo {
    std::vector<size_t> findAllStringsAhoCorasick(const std::string &text, const std::vector<std::string>& patterns) {
        Node *root = new Node();
        std::vector<size_t> occurences;
        Node *cur = root;
        for (size_t i = 0; i < patterns.size(); ++i)
            addString(&patterns[i], i, root);
        for (size_t i = 0; i < text.size(); ++i) {
            char letter = text[i] - 'a';
            cur = changeState(cur, letter, root);
            if (cur->isTerminal)
                occurences.emplace_back(cur->stringNum);
            // TODO: make return of current position in text and number of string in pair
        }
        // TODO: recursive delete of tree
        return occurences;
    }
}

