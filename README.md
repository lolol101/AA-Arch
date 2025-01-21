# AA-Arch

### This project's goal is to implement several string-searching algorithms. 

The following algorithms are intended to be implemented:
1. The Aho-Korasik algorithm

The algorithm searches for a set of substrings from the dictionary in a given string using finite automaton approach. All possible matches are found for each substring in a dictionary.

Time - O(n|$\Sigma$| + H + k)\
Space - (n|$\Sigma$|)\
Where n is the cumulative length of the dictionary, |$\Sigma$| is the length of the alphabet, H is the length of the string and k is total number of occurences.

2. The Knuth-Morris-Pratt algorithm
The algorithm 

The algorithm searches for all occurence of substring in a given string using the occuring mismatch data to calculate next possible match start.

Time - O(n + m)\
Space - (m)\
Where n is the length of string and m is the length of substring.

3. The Rabin-Karp algorithm

This algorithm searches for all occurences of the substring in a string using polynomial hashing.

Time - O(n + m) average, O(nm) worst\
Space - (1)\
Where n is the length of string and m is the length of substring.

4. The Boyer-Moore algorithm
5. Longest Common Substring (LCS)
6. Longest Increasing Subsequence (LIS)
