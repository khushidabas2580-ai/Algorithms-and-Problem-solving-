# Algorithms & Problem Solving (Sorting / Searching / Greedy)
## Project Overview
This project demonstrates the implementation and analysis of fundamental algorithms used in problem solving. It includes examples of **sorting**, **searching**, and **greedy optimization** techniques implemented in C++. The project evaluates each algorithm's correctness, efficiency, and computational complexity through multiple test cases and runtime analysis.
---
## Objectives
- Implement fundamental algorithms in C++.
- Demonstrate sorting, searching, and greedy approaches.
- Compare algorithm performance using different input sizes.
- Analyze time and space complexity.
- Provide reusable and modular source code.
---
## Algorithms Implemented
### 1. Merge Sort
- Divide and Conquer algorithm
- Stable sorting algorithm
- Time Complexity: **O(n log n)**
- Space Complexity: **O(n)**
### 2. Binary Search
- Efficient searching algorithm for sorted arrays
- Time Complexity:
  - Best Case: **O(1)**
  - Average/Worst Case: **O(log n)**
- Space Complexity:
  - Iterative: **O(1)**
### 3. Fractional Knapsack (Greedy)
- Greedy optimization algorithm
- Selects items based on value-to-weight ratio
- Time Complexity: **O(n log n)**
- Space Complexity: **O(1)** (excluding sorting)
---
## Project Structure
```
Task2-Algorithms/
│
├── src/
│   ├── merge_sort.cpp
│   ├── binary_search.cpp
│   ├── fractional_knapsack.cpp
│
├── include/
│   ├── merge_sort.h
│   ├── binary_search.h
│   └── knapsack.h
│
├── test/
│   ├── test_merge_sort.cpp
│   ├── test_binary_search.cpp
│   └── test_knapsack.cpp
│
├── sample_inputs/
│   ├── merge_input.txt
│   ├── binary_input.txt
│   └── knapsack_input.txt
│
├── report/
│   └── Task2_Report.pdf
│
├── README.md
```
---
## Requirements
- C++11 or later
- GCC/G++ Compiler
---
## Compilation
Compile using G++:
```bash
g++ src/merge_sort.cpp -o merge_sort
g++ src/binary_search.cpp -o binary_search
g++ src/fractional_knapsack.cpp -o fractional_knapsack
```
Or compile using the Makefile:
```bash
make
```
---
## Running the Programs
### Merge Sort
```bash
./merge_sort
```
### Binary Search
```bash
./binary_search
```
### Fractional Knapsack
```bash
./fractional_knapsack
```
---
## Sample Input
### Merge Sort
```
45 12 89 34 67 23 90 11 54 28
```
### Binary Search
```
Array:
5 8 12 17 23 31 45 52 67 89
Target:
45
```
### Fractional Knapsack
```
Capacity = 50
Items
Weight  Value
10      60
20      100
30      120
```
---
## Sample Output
### Merge Sort
```
11 12 23 28 34 45 54 67 89 90
```
### Binary Search
```
Element found at index 6
```
### Fractional Knapsack
```
Maximum Profit = 240
```
---
## Complexity Analysis

| Algorithm | Best | Average | Worst | Space |
|------------|------|----------|--------|--------|
| Merge Sort | O(n log n) | O(n log n) | O(n log n) | O(n) |
| Binary Search | O(1) | O(log n) | O(log n) | O(1) |
| Fractional Knapsack | O(n log n) | O(n log n) | O(n log n) | O(1)* |
> *Excluding the space required for sorting.
---
## Testing
The algorithms were tested with multiple input sizes to verify:
- Correctness
- Execution time
- Scalability
- Complexity analysis
Example input sizes:
- 1,000 elements
- 5,000 elements
- 10,000 elements
- 50,000 elements
---
## Learning Outcomes
- Understanding Divide and Conquer algorithms.
- Efficient searching techniques.
- Greedy optimization methods.
- Runtime and complexity analysis.
- Modular C++ programming.
---
## Author
**Name:** *Khushi*  
**Course:** Diploma in Computer Engineering  
**Task:** Task 2 – Algorithms & Problem Solving  
**Language:** C++
---
## License
This project is developed for educational purposes.