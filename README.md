# Reading References
**Book**: The Algorithm Design Manual - Steven S. Skiena

## Writing LaTeX & Math Equations
- use an [online LaTeX editor](http://www.sciweavers.org/free-online-latex-equation-editor) to generate the `.png`
- `curl -o assets/foo.png https://123.png`
- Markdown `![LaTeX Equation][ref_name]`
- Markdown Ref `[ref_name]: assets/foo.png "image mouseover caption"`

## Introduction

## Big O Dominance Order
α: Ackerman's Function

![Dominance Chain][dom_chain]

## Data Structures
- Arrays
- List (linked list)
- Stack
- Queue
- Dictionary
- Binary Search Tree
- Balanced Search Tree
- Priority Queue
- Heap
- String
- Graph (adjacency matrices/lists)
- Set

### Logarithm
- lg: log_2
- ln: log_e
- log: log_10

## Efficiency Reference
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

## Sample String Hash

Simple pattern searching of string _S_ with pattern _p_, naïve looping gives **O(mn)** where _m=|p| n=|S|_. With hashing the expected case
can be reduced down to **O(m+n)**.
- α: size of the alphabet
- S: string
- m: size of hash table, ideally a large prime not too close to 2^i - 1
- ![String Hash Equation][str_hash]
- key: H(S) % m
The key is that finding the next window of _m_ characters can be calculated using:
![String Hash j plus one][str_hash_plus_one]

## Heap

Maintains a partial order on the set of elements which is weaker than the sorted order (efficient to maintain), yet stronger than random order(easier to find min).

**Max Heap** the parent has a key _>=_ than its children.

**Min Heap** the parent has a key _<=_ than its children.

Insertion takes at most O(logn) as the height is ![lg n][lg_n], thus creation of a heap takes at most ![n lg n][n_lg_n].

Heap construction time can be increased to linear by using _bubble down_ insertion, as only _n/2_ leafs travel all of ![lg n][lg_n], _n/4_ at height _1_, _n/8_ at height _2_ and so on. The cost becomes:

![Heap Bubble Down][heap_bubble_d]

**A Heap is not a Binary Tree**

## Sort
- Heap Sort ![n log n][n_lg_n]
- Merge Sort ![n log n][n_lg_n]
- Quick Sort (worst case n^2, _random_ case ![n log n][n_lg_n] with high probability)

## Graphs
- undirected / directed
- unweighted / weighted
- simple / non-simple (loop, dupe edge)
- sparse / dense
- cyclic / acyclic
- embedded / topological
- explicit / implicit
- unlabelled / labelled

### Graph Data Structures
**Adjacency Matrix**, rapid membership lookup, may use excessive space.

**Adjacency List**, linked list, slower lookup, less space.

DFS | BFS
--- | ---
Stack | Queue

- BFS: good for finding shortest path to a vertex (unweighted graph), or test graph validity such as bipartite graphs
- DFS: can use recursion rather than an explicit stack, has backtracking, easily find cycles from tree edges and back edges

- [Topological Sorting](https://en.wikipedia.org/wiki/Topological_sorting), DFS on Directed Acyclic Graph (DAG) for scheduling sequence of tasks with dependencies
- [Strongly Connected Components](https://en.wikipedia.org/wiki/Strongly_connected_component), DFS on directed graphs to find pockets of vertices that can reach each other

**Minimum Spanning Tree**, shortest cost to connect all vertices (roads, telephone wires, etc).
- [Prim's Algorithm](https://en.wikipedia.org/wiki/Prim%27s_algorithm), from an arbitrary vertex, find cheapest neighbour.
- [Kruskal's Algorithm](https://en.wikipedia.org/wiki/Kruskal's_algorithm), find cheapest edges as long as they don't form a cycle.

### Weighted Graphs
- [Dijkstra's Algorithm](https://en.wikipedia.org/wiki/Dijkstra's_algorithm), similar to Prim's MST, greedy find shortest path.
- [Floyd-Warshall Algo](https://en.wikipedia.org/wiki/Floyd%E2%80%93Warshall_algorithm), find all-pairs shortest path, indirectly, transitive closure.

## Combinatorial Search & Heuristic Methods
- (no notes) backtracking, search pruning (local count vs look ahead)

**Heuristic Search Methods**: random sampling, gradient-descent, simulated annealing
- _solution space representation_ - complete & concise description of the set of possible solutions. e.g. for TSP, the solution space is (n-1)!, represented by _S_ of _n - 1_ vertices.
- _cost function_ - access quality of elements in the solution space. e.g. for TSP, the cost function sums up the weight of all edges _(Si, Si+1)_, where _Sn+1_ denotes _v1_.
 
### Random Sampling
- when there are a high proportion of acceptable solution (e.g. finding _hay_ in a hay stack)
- where there is no coherence in the solution space (e.g. find a friend whose phone number ends in `00`)

### Local Search (gradient-descent)
Pick a vertex and search neighbouring verticies, find a favourable transition as the next step. This leads to local maximum/minimum, but not necessarily global.
- _where there is great coherence in the solution space_, when the solution space is convex (the local hill is the global hill)
- _whenever the cost of incremental evaluation is much cheaper than global evaluation_, e.g. in TSP, once there's a candidate solution, swapping one edge for another is constant, trivial

### Simulated Annealing
The idea is to allow sub-optimal transitions to avoid being trapped in a local maximum. Energy transition probability of cooling metal, from energy ei to ej at temperature T: ![Transition Probability][trans_prob]

**Cooling Schedule**:
- _initial system temperature_, typically t1 = 1
- _temperature decrement function = typically ![Temp Decrement Function][temp_dec], where `0.8 < a <= 0.99`, i.e. exponential decay
- _num of iterations between temp change_, typically 100 to 1000
- _acceptance criteria_, typically when `C(si + 1) < C(si)`, accept any transition, and accept negative transitions when ![Negative Acceptance Criteria][accep_cri] where `r` is a random number `0 <= r < 1`. Constant `k` normalises the cost func so almost all transitions are accepted at the starting temprature
- _stop criteria_, typically when value of current solution hasn't changed within ≈ the last iteration




[//]: # (Below are Markdown References)

[lg_n]: assets/lg_n.png "\log_2 n"
[n_lg_n]: assets/n_lg_n.png "n \log_2 n"
[str_hash]: assets/str_hash.png "H(S) = \sum_{i=0}^{|S|-1}  \alpha^{|S|-(i+1)} \times char(s_i)"
[str_hash_plus_one]: assets/str_hash_plus_one.png "H(S, j+1) = \alpha(H(S, j) - \alpha^{m-1}char(s_j)) + char(s_{j+m})"
[dom_chain]: assets/dom_chain.png "n! \gg c^n \gg n^3 \gg n^2 \gg n^{1+ \epsilon} \gg n \log n \gg n \gg n^{-1} \gg \log^2 n \gg \log n \gg \frac{\log n}{\log\log n} \gg \log\log n \gg \alpha(n) \gg 1"
[heap_bubble_d]: assets/heap_bubble_d.png " \sum_{h=0}^{\lfloor \lg n \rfloor} \lceil n/2^{h+1}\rceil h \leq n \sum_{h=0}^{\lfloor\lg n\rfloor} h/2^h \leq 2n"
[trans_prob]: assets/trans_prob.png "P(e_i, e_j, T) = e^{ \frac{e_i-e_j}{k_BT} }"
[temp_dec]: assets/temp_dec.png "t_k = \alpha  \times t_{k-1}"
[accep_cri]: assets/accep_cri.png "e^{-\frac{C(s_i) - C(S_i + 1)}{k \times t_i}} \geq r"
