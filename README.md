# Reading References
**Book**: The Algorithm Design Manual - Steven S. Skiena

## Writing LaTeX & Math Equations
- use an [online LaTeX editor](http://www.sciweavers.org/free-online-latex-equation-editor) to generate the `.png`
- `curl -o assets/foo.png https://123.png`
- Markdown `![LaTeX Equation][ref_name]`
- Markdown Ref `[ref_name]: assets/foo.png "image mouseover caption"`

## Introduction

### Big O Dominance Order
α: Ackerman's Function

![Dominance Chain][dom_chain]

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

### Efficiency Reference
_* denotes a C pointer_

Dictionary Operation | Unsorted Array | Sorted Array
--- | --- | ---
Search(L, k) | O(n) | O(logn)
Insert(L, * x) | O(1) | O(n)
Delete(L, * x) | O(1)$ | O(n)
Successor(L, * x) | O(n) | O(1)
Predecessor(L, * x) | O(n) | O(1)
Min(L) | O(n) | O(1)
Max(L) | O(n) | O(1)

_$ Deletion can be quickened by filling in the hole with A[n] and decrement n_

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

### Sample String Hash



- α: size of the alphabet
- S: string
- m: size of hash table, ideally a large prime not too close to 2^i - 1
- ![String Hash Equation][str_hash]
- key: H(S) % m

[str_hash]: assets/str_hash.png "H(S) = \sum_{i=0}^{|S|-1}  \alpha^{|S|-(i+1)} \times char(s_i)"
[dom_chain]: assets/dom_chain.png "n! \gg c^n \gg n^3 \gg n^2 \gg n^{1+ \epsilon} \gg n \log n \gg n \gg n^{-1} \gg \log^2 n \gg \log n \gg \frac{\log n}{\log\log n} \gg \log\log n \gg \alpha(n) \gg 1"
