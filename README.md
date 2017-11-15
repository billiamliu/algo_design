# Reading References
**Book**: The Algorithm Design Manual - Steven S. Skiena

## Introduction

### Big O Dominance Order
n! >> c^n >> n^3 >> n^2 >> n^(1 + ε) >> nlogn >> n >> n^-1 >> log^(2)n >> logn >> logn / loglogn >> loglogn >> α(n) Ackerman >> 1

### Data Structures
- Arrays
- List (linked list)
- Stack
- Queue
- Dictionary
- Binary Search Tree
- Balanced Search Tree
- Priority Queue
- String
- Graph (adjacency matrices/lists)
- Set

Dictionary Operation | Unsorted Array | Sorted Array
--- | --- | ---
Search(L, k) | O(n) | O(logn)
Insert(L, * x) | O(1) | O(n)
Delete(L, * x) | O(1)$ | O(n)
Successor(L, * x) | O(n) | O(1)
Predecessor(L, * x) | O(n) | O(1)
Min(L) | O(n) | O(1)
Max(L) | O(n) | O(1)

$ Deletion can be quickened by filling in the hole with A[n] and decrement n.

Dictionary Operation | Singly Unsorted | Double Unsorted | Singly Sorted | Double Sorted
--- | --- | --- | --- | ---
Search(L, k) | O(n) | O(n) | O(n) | O(n)
Insert(L, * x) | O(1) | O(1) | O(n) | O(n)
Delete(L, * x) | O(n) | O(1) | O(n) | O(1)
Successor(L, * x) | O(n) | O(n) | O(1) | O(1)
Predecessor(L, * x) | O(n) | O(n) | O(n) | O(1)
Min(L) | O(n) | O(n) | O(1) | O(1)
Max(L) | O(n) | O(n) | O(1) | O(1)

Find Min | Unsorted Array | Sorted Array | Balanced Tree
--- | --- | --- | ---
Insert(Q, * x) | O(1) | O(n) | O(logn)
FindMin(Q) | O(1) | O(1) | O(1)
DeleteMin(Q) | O(n) | O(1) | O(logn)
