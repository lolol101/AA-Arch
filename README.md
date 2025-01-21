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

A general-purpose algorithm designed to find substrings in a string. The advantage of this algorithm is that at the cost of some preliminary calculations on the template, the template is not compared with the source text in all positions — some 
checks are skipped as obviously not yielding results.

Time - O(n + m + C) \
Space - O(m + C) \
Where n and m are the lengths of the strings.

5. Longest Common Substring (LCS)

A longest common substring of two or more strings is a longest string that is a substring of all of them.

Time - O(nm)\
Space - O(1) \
Where n and m are the length of strings.

6. Suffix Tree searching algorithm

An algorithm of searching substring in a string using suffix tree.

Time - O(SuffixTreeBuilding) + O(n) \
Space - O(n|$\Sigma$|) \
Where n is the length of the text.

