# Algorithms & Complexity

A collection of implementations and notes on algorithms and data structures for my Algorithms & Complexity course at the University of San Carlos.

## Contents

- [Sorting Algorithms](#sorting-algorithms)
- [Trees](#trees)
- [Graphs](#graphs)
- [Others](#others)

---

## Sorting Algorithms

### Quick Sort
- **Best:** O(n log n) | **Average:** O(n log n) | **Worst:** O(n²)
- **Space:** O(log n)
- Divide-and-conquer using pivot partitioning; fast in practice despite worst-case quadratic time.

### Merge Sort
- **Best:** O(n log n) | **Average:** O(n log n) | **Worst:** O(n log n)
- **Space:** O(n)
- Recursively divides the array into halves, sorts each, and merges them back together.

### Heap Sort
- **Best:** O(n log n) | **Average:** O(n log n) | **Worst:** O(n log n)
- **Space:** O(1)
- Builds a max heap, then repeatedly extracts the maximum to produce a sorted array.

### Bubble Sort
- **Best:** O(n) | **Average:** O(n²) | **Worst:** O(n²)
- **Space:** O(1)
- Repeatedly swaps adjacent out-of-order elements; simple but inefficient on large inputs.

### Insertion Sort
- **Best:** O(n) | **Average:** O(n²) | **Worst:** O(n²)
- **Space:** O(1)
- Builds a sorted array one element at a time; efficient for small or nearly-sorted inputs.

### Selection Sort
- **Best:** O(n²) | **Average:** O(n²) | **Worst:** O(n²)
- **Space:** O(1)
- Repeatedly finds the minimum element and places it at the front of the unsorted portion.

### Counting Sort
- **Best:** O(n + k) | **Average:** O(n + k) | **Worst:** O(n + k)
- **Space:** O(k)
- Non-comparison sort that counts occurrences of each value; only works on integer ranges.

### Radix Sort
- **Best:** O(d(n + k)) | **Average:** O(d(n + k)) | **Worst:** O(d(n + k))
- **Space:** O(n + k)
- Sorts integers digit by digit from least to most significant using a stable sub-sort.

### Bucket Sort
- **Best:** O(n + k) | **Average:** O(n + k) | **Worst:** O(n²)
- **Space:** O(n + k)
- Distributes elements into buckets and sorts each bucket individually; works well on uniformly distributed data.

---

## Trees

### Binary Search Tree (BST)
- **Insert:** O(log n) avg, O(n) worst | **Delete:** O(log n) avg, O(n) worst | **Search:** O(log n) avg, O(n) worst
- **Space:** O(n)
- A binary tree where each node's left subtree contains smaller values and the right subtree contains larger values. Performance degrades to O(n) on unbalanced inputs.

### AVL Tree
- **Insert:** O(log n) | **Delete:** O(log n) | **Search:** O(log n)
- **Space:** O(n)
- A self-balancing BST that maintains a balance factor of -1, 0, or 1 at every node via rotations. Guarantees O(log n) operations at the cost of more frequent rotations compared to Red-Black trees.

### Red-Black Tree
- **Insert:** O(log n) | **Delete:** O(log n) | **Search:** O(log n)
- **Space:** O(n)
- A self-balancing BST with color properties (red/black) that ensure the tree stays approximately balanced. Fewer rotations than AVL on insertion/deletion; used in many standard library implementations.

### B-Tree
- **Insert:** O(log n) | **Delete:** O(log n) | **Search:** O(log n)
- **Space:** O(n)
- A generalized balanced tree where nodes can hold multiple keys and children. Designed for disk-based storage systems; minimizes I/O by keeping the tree wide and shallow.

### B* Tree
- **Insert:** O(log n) | **Delete:** O(log n) | **Search:** O(log n)
- **Space:** O(n)
- A variant of the B-Tree that requires nodes to be at least 2/3 full instead of 1/2. Delays splits by redistributing keys among siblings, resulting in better space utilization.

### B+ Tree
- **Insert:** O(log n) | **Delete:** O(log n) | **Search:** O(log n)
- **Space:** O(n)
- A B-Tree variant where all data is stored in leaf nodes, which are linked together in a linked list. Supports efficient range queries; widely used in database indexing and file systems.

---

## Graphs

### Depth-First Search (DFS)
- **Time:** O(V + E) | **Space:** O(V)
- Explores as far as possible along each branch before backtracking. Used for cycle detection, connected components, and topological sorting.

### Breadth-First Search (BFS)
- **Time:** O(V + E) | **Space:** O(V)
- Explores all neighbors at the current depth before moving to the next level. Finds shortest paths in unweighted graphs.

### Topological Sort
- **Time:** O(V + E) | **Space:** O(V)
- A linear ordering of vertices in a DAG such that every directed edge u → v has u before v. Typically implemented via DFS or Kahn's algorithm (BFS-based).

### Dijkstra's Algorithm
- **Time:** O((V + E) log V) with a priority queue | **Space:** O(V)
- Finds the shortest path from a single source to all other vertices. Requires non-negative edge weights; greedy approach using a min-heap.

### Bellman-Ford Algorithm
- **Time:** O(VE) | **Space:** O(V)
- Finds shortest paths from a single source, supporting negative edge weights. Can detect negative weight cycles; slower than Dijkstra but more general.

---

## Others

### Skip List
- **Insert:** O(log n) avg, O(n) worst | **Delete:** O(log n) avg, O(n) worst | **Search:** O(log n) avg, O(n) worst
- **Space:** O(n log n) avg
- A probabilistic data structure built from layered sorted linked lists. Higher layers act as express lanes for faster traversal; offers BST-like performance without complex balancing logic.

### Floyd-Warshall Algorithm
- **Time:** O(V³) | **Space:** O(V²)
- Finds shortest paths between all pairs of vertices using dynamic programming. Handles negative weights and detects negative cycles; best for dense graphs where all-pairs paths are needed.

### Johnson's Algorithm
- **Time:** O(V² log V + VE) | **Space:** O(V²)
- Computes all-pairs shortest paths by reweighting edges to eliminate negatives, then running Dijkstra from every vertex. More efficient than Floyd-Warshall on sparse graphs with negative weights.

### Dynamic Programming
- **Time:** Varies by problem | **Space:** Varies by problem
- An optimization technique that solves problems by breaking them into overlapping subproblems and storing their results to avoid redundant computation. Can be implemented top-down (memoization) or bottom-up (tabulation). Classic problems include Fibonacci, Knapsack, Longest Common Subsequence, and Coin Change.
