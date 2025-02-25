#include "AhoCorasick.hpp"

#include <catch2/catch_test_macros.hpp>

using namespace algo::util::ahocorasick;

TEST_CASE("Test moveToNextState", "[unit][aho-corasick]") {
    std::vector<BorTreeNode> vertexes(1); // initialized with root node

    SECTION("Correctly handles basic movement") {
        addString("abc", 0, vertexes);
        REQUIRE(moveToNextState(0, 'a', vertexes) == 1);
        REQUIRE(moveToNextState(1, 'b', vertexes) == 2);
        REQUIRE(moveToNextState(2, 'c', vertexes) == 3);
    }

    SECTION("Returns to root if no children with appropriate char links are present") {
        addString("abc", 0, vertexes);
        REQUIRE(moveToNextState(0, 'x', vertexes) == 0);
        REQUIRE(moveToNextState(2, 'x', vertexes) == 0);
    }

    SECTION("Correctly handles step from same vertex to different children") {
        addString("ab", 0, vertexes);
        addString("ac", 1, vertexes);
        REQUIRE(moveToNextState(1, 'b', vertexes) == 2);
        REQUIRE(moveToNextState(1, 'c', vertexes) == 3);
    }
}

TEST_CASE("Test getSuffLink", "[unit][aho-corasick]") {
    std::vector<BorTreeNode> vertexes(1); // Initialize with root node

    SECTION("Root node is linked to itself") {
        REQUIRE(getSuffLink(0, vertexes) == 0);
    }

    SECTION("Direct child of root is linked to root") {
        addString("a", 0, vertexes);
        REQUIRE(getSuffLink(1, vertexes) == 0);
    }

    // TODO: test complex suffix links
}

TEST_CASE("Test addString", "[unit][aho-corasick]") {
    std::vector<BorTreeNode> vertexes(1); // Initialize with root node

    SECTION("Correctly adds a single character string") {
        addString("a", 0, vertexes);
        
        REQUIRE(vertexes.size() == 2);

        BorTreeNode &vertexA = vertexes[1];
        REQUIRE(vertexA.parentChar == 'a');
        REQUIRE(vertexA.isTerminal == true);
        REQUIRE(vertexA.deep == 1);
        REQUIRE(vertexA.stringNum == 0);
    }

    SECTION("Correctly adds a multi-character string") {
        addString("abc", 0, vertexes);
        
        REQUIRE(vertexes.size() == 4);

        REQUIRE(vertexes[3].isTerminal == true);
        REQUIRE(vertexes[3].deep == 3);
        REQUIRE(vertexes[3].stringNum == 0);
    }
    
    SECTION("Correctly adds multiple non-intersecting strings") {
        addString("abc", 0, vertexes);
        addString("def", 1, vertexes);

        // expected trie struct: Root -> A -> B -> C
        //                           \-> D -> E -> F
        REQUIRE(vertexes.size() == 7);
        
        BorTreeNode &vertexC = vertexes[3];
        REQUIRE(vertexC.parentChar == 'c');
        REQUIRE(vertexC.isTerminal == true);
        REQUIRE(vertexC.stringNum == 0);
        
        BorTreeNode &vertexD = vertexes[6];
        REQUIRE(vertexD.parentChar == 'f');
        REQUIRE(vertexD.isTerminal == true);
        REQUIRE(vertexD.stringNum == 1);
    }

    SECTION("Correctly adds multiple intersecting strings") {
        addString("abc", 0, vertexes);
        addString("abd", 1, vertexes);

        // expected trie struct: Root -> A -> B -> C/D 2 children
        REQUIRE(vertexes.size() == 5);
        
        BorTreeNode &vertexC = vertexes[3];
        REQUIRE(vertexC.parentChar == 'c');
        REQUIRE(vertexC.isTerminal == true);
        REQUIRE(vertexC.stringNum == 0);
        
        BorTreeNode &vertexD = vertexes[4];
        REQUIRE(vertexD.parentChar == 'd');
        REQUIRE(vertexD.isTerminal == true);
        REQUIRE(vertexD.stringNum == 1);
    }
}