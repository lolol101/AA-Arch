# AA-Arch

Contributors: Nazarov Maksim, Okorokov Nikita.

## Description

Goal of this project is to implement several string-searching algorithms.

Currently implemented:
1. The Aho-Korasik algorithm
2. The Knuth-Morris-Pratt algorithm
3. The Rabin-Karp algorithm
4. The Boyer-Moore algorithm

To be implemented:

5. Longest Common Substring (LCS)
6. Suffix Tree searching algorithm

## Build

To build the project in Linux, use following terminal commands from project directory:
```
cmake .
make StringLib
make Test
```
To run tests after build:
```
./build/Test
```

To run specific tests (e.g. "aho-corasik" or "unit"; check test directory README for available tags):
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

## Launching the benchmark

```
./build/Benchmark --benchmark_format=json > ./benchmark/results.json
```

See benchmark results in benchmark/results.json

## Library contribution guide

Starting point: you have your implementation of the algorithm in source/header files, e.g. "MyAlgo.hpp" and "MyAlgo.cpp".

1. Put your header "MyAlgo.hpp" in "include" folder at the project root.
2. Add following directive to 'algorithm.hpp'
```
#include "MyAlgo.hpp"
```
3. Add your source files to CMakeLists.txt to StringLib target library:
```
add_library(StringLib STATIC 
    ...
    src/MyAlgo.cpp
    ...
)
```

Now your algorithm can be used in standard way like the rest of the library.