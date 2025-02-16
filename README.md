# AA-Arch

Contributors: Nazarov Maksim, Okorokov Nikita.

## Description

Goal of this project is to implement several string-searching algorithms. The following algorithms are intended to be implemented:
1. The Aho-Korasik algorithm
2. The Knuth-Morris-Pratt algorithm
3. The Rabin-Karp algorithm
4. The Boyer-Moore algorithm
5. Longest Common Substring (LCS)
6. Suffix Tree searching algorithm

Currently implemented:
1. The Aho-Korasik algorithm
2. The Knuth-Morris-Pratt algorithm
3. The Rabin-Karp algorithm

## Build

How to build out project in Linux:
```
cmake .
make StringLib
make Test
```
Test run after build:
```
./build/Test
```

Specific Test run (e.g. "aho-corasik" or "unit"):
```
./build/Test [aho-corasik]
```

## Integration of library
Method using Git and Cmake:
* Add submodule

```
git add submodule https://github.com/lolol101/AA-Arch/
git submodule update --init
```

* After that add to your Cmakelists.txt:
```
add_subdirectory(path_to_lib/AA-Arch)
target_link_libraries(Test PRIVATE StringLib)
```

* Then you can use library header files from: 
```
"path_to_lib/AA-Arch/include/"
```