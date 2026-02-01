# Algorithms & Complexity Notes

A comprehensive collection of notes on algorithms, data structures, and computational complexity theory.

## Contents

- [Big O Notation](#big-o-notation)
- [Common Time Complexities](#common-time-complexities)
- [Sorting Algorithms](#sorting-algorithms)
- [Search Algorithms](#search-algorithms)
- [Data Structures](#data-structures)
- [Graph Algorithms](#graph-algorithms)
- [Dynamic Programming](#dynamic-programming)
- [Complexity Classes](#complexity-classes)

## Big O Notation

Big O notation describes the upper bound of an algorithm's time or space complexity as the input size grows.

**Key Concepts:**
- **O(1)** - Constant time: execution time doesn't depend on input size
- **O(log n)** - Logarithmic: typically seen in divide-and-conquer algorithms
- **O(n)** - Linear: execution time grows directly with input size
- **O(n log n)** - Linearithmic: common in efficient sorting algorithms
- **O(n²)** - Quadratic: often seen in nested loops
- **O(2ⁿ)** - Exponential: typically recursive solutions exploring all combinations
- **O(n!)** - Factorial: usually brute-force permutation problems

## Common Time Complexities

| Complexity | Name | Example Operations |
|------------|------|-------------------|
| O(1) | Constant | Array access, hash table lookup |
| O(log n) | Logarithmic | Binary search, balanced tree operations |
| O(n) | Linear | Array traversal, linear search |
| O(n log n) | Linearithmic | Merge sort, heap sort, quicksort (average) |
| O(n²) | Quadratic | Bubble sort, insertion sort, selection sort |
| O(n³) | Cubic | Matrix multiplication (naive) |
| O(2ⁿ) | Exponential | Recursive fibonacci, subset generation |
| O(n!) | Factorial | Traveling salesman (brute force) |

## Sorting Algorithms

### Quick Sort
- **Average Time:** O(n log n)
- **Worst Time:** O(n²)
- **Space:** O(log n)
- **Strategy:** Divide-and-conquer using pivot partitioning

### Merge Sort
- **Time:** O(n log n)
- **Space:** O(n)
- **Strategy:** Divide array, recursively sort, merge sorted halves

### Heap Sort
- **Time:** O(n log n)
- **Space:** O(1)
- **Strategy:** Build max heap, repeatedly extract maximum

### Bubble Sort
- **Time:** O(n²)
- **Space:** O(1)
- **Strategy:** Repeatedly swap adjacent elements if out of order

### Insertion Sort
- **Time:** O(n²) worst, O(n) best
- **Space:** O(1)
- **Strategy:** Build sorted array one element at a time

## Search Algorithms

### Binary Search
- **Time:** O(log n)
- **Space:** O(1)
- **Requirements:** Sorted array
- **Strategy:** Repeatedly divide search interval in half

### Linear Search
- **Time:** O(n)
- **Space:** O(1)
- **Strategy:** Check each element sequentially

### Depth-First Search (DFS)
- **Time:** O(V + E)
- **Space:** O(V)
- **Use cases:** Path finding, cycle detection, topological sorting

### Breadth-First Search (BFS)
- **Time:** O(V + E)
- **Space:** O(V)
- **Use cases:** Shortest path in unweighted graphs, level-order traversal

## Data Structures

### Arrays
- **Access:** O(1)
- **Search:** O(n)
- **Insert/Delete:** O(n)

### Linked Lists
- **Access:** O(n)
- **Search:** O(n)
- **Insert/Delete:** O(1) with pointer

### Hash Tables
- **Average Access/Insert/Delete:** O(1)
- **Worst case:** O(n)

### Binary Search Trees
- **Average Access/Insert/Delete:** O(log n)
- **Worst case:** O(n)

### Balanced Trees (AVL, Red-Black)
- **All operations:** O(log n)

### Heaps
- **Insert:** O(log n)
- **Delete Max/Min:** O(log n)
- **Get Max/Min:** O(1)

### Graphs
- **Adjacency Matrix:** O(V²) space, O(1) edge lookup
- **Adjacency List:** O(V + E) space, O(degree) edge lookup

## Graph Algorithms

### Dijkstra's Algorithm
- **Time:** O((V + E) log V) with priority queue
- **Purpose:** Shortest path from single source (non-negative weights)

### Bellman-Ford
- **Time:** O(VE)
- **Purpose:** Shortest path with negative weights, detects negative cycles

### Floyd-Warshall
- **Time:** O(V³)
- **Purpose:** All-pairs shortest paths

### Kruskal's Algorithm
- **Time:** O(E log E)
- **Purpose:** Minimum spanning tree

### Prim's Algorithm
- **Time:** O((V + E) log V)
- **Purpose:** Minimum spanning tree

## Dynamic Programming

Dynamic programming solves problems by breaking them into overlapping subproblems and storing results to avoid redundant computation.

**Classic Problems:**
- Fibonacci sequence
- Longest common subsequence
- Knapsack problem
- Coin change
- Edit distance
- Matrix chain multiplication

**Approaches:**
- **Top-down (Memoization):** Recursive with caching
- **Bottom-up (Tabulation):** Iterative, build solution from base cases

## Complexity Classes

### P (Polynomial Time)
Problems solvable in polynomial time by a deterministic Turing machine.

### NP (Nondeterministic Polynomial Time)
Problems where solutions can be verified in polynomial time.

### NP-Complete
Hardest problems in NP. If any NP-complete problem has a polynomial-time solution, then P = NP.

**Examples:** SAT, Traveling Salesman, Graph Coloring, Subset Sum

### NP-Hard
At least as hard as NP-complete problems, but not necessarily in NP.

## Master Theorem

For recurrence relations of the form: T(n) = aT(n/b) + f(n)

1. If f(n) = O(n^(log_b(a) - ε)), then T(n) = Θ(n^log_b(a))
2. If f(n) = Θ(n^log_b(a)), then T(n) = Θ(n^log_b(a) × log n)
3. If f(n) = Ω(n^(log_b(a) + ε)), then T(n) = Θ(f(n))

## Space Complexity

Space complexity measures the total memory used by an algorithm relative to input size.

**Components:**
- **Auxiliary space:** Extra space used by the algorithm
- **Input space:** Space taken by the input itself

## Amortized Analysis

Analyzes the average performance of operations over a sequence, accounting for expensive operations that occur infrequently.

**Techniques:**
- Aggregate method
- Accounting method
- Potential method

## Contributing

Feel free to submit pull requests or open issues to improve these notes.

## License

This project is open source and available under the MIT License.
