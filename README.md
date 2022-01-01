# CP-Templates
A Collection of Templates for different data structures that I use in Competitive programming.

## Usage:

* **`CENTROID DECOMPOSITION :-`**

    Centroid<_datatype_> tree_name(_size_);

    _datatype_: The data type to be stored in the tree.
    _size_: The Number of nodes in the tree.

    **Example:-**

    Centroid<int> g(n);

    This creates a tree with n nodes (1 based indexing).
    
    **Functions:-**
    
    clear(): Takes one parameter n, the size of tree and creates a new tree of size n.

    centroid(): Takes one parameter root, the root of the tree and returns all centroids of the tree.

    decompose(): Takes no parameters and is used to decompose the tree by recursively removing the centroid.

* **`DISJOINT SET UNION :-`**

    union_find<_datatype_> dsu_name(_size_);

    _datatype_: The data type to be stored in DSU.
    _size_: The size of DSU.

    **Example:-**

    union_find<int> dsu(n);

    This creates a DSU with n nodes, 1 based indexing.

    **Functions:-**

    root(): Takes one parameter u, the node who's root is to be found, and returns the root of that component.

    find(): Takes two parameters u, v, the two nodes who's connectivity is to be checked, and returns true if both belong to the same connected component.

    merge(): Takes two parameters u, v, the two nodes to be merged, and merges them into single connected component.

* **`FENWICK TREE :-`**

    fenwick_tree<_datatype_> tree_name(_size_, _function_);

    _datatype_: The data type to be stored in fenwick tree.
    _size_: Size of the fenwick tree.
    _function_: The function that fenwick tree computes. It is an optional Parameter. By default, fenwick tree is created to compute sum queries.

    **Example:-**

    fenwick_tree<int> ft(n);

    This creates a fenwick tree of size n + 1 for sum queries.

    fenwick_tree<int> ft(n, [&](int x, int y) {
        return min(x, y);
    });

    This creates a fenwick tree of size n + 1 for min queries.

    **Functions:-**

    compute(): Takes one parameter r, the end point of the query, and returns answer for the range 0 to r (inclusive). It works on 0 based indexing.

    update(): Takes two parameters idx and val, the position to be updated and the new value and updates the fenwick tree.
    

* **`LCA (BINARY LIFTING) :-`**

    lca tree_name(_size_);

    _size_: The size of Tree.

    **Example:-**

    lca g(n);

    This creates a tree with n nodes, 1 based indexing.

    **Functions:-**


    is_ancestor(): Takes two parameters u, v and returns true if u is ancestor of v.

    dist(): Takes two parameters u, v and returns the distance between u and v.

    dfs(): Takes two parameters node and par, the node and its parent, and a third optional parameter d, which is the level of the node. It does the precomputation required for LCA.

    find(): Takes two parameters u, v and returns LCA(u, v).

* **`MODULAR ARITHMETIC :-`**

    modular<_maxval_> name;

    _maxval_: The value upto which factorials and inverse factorials are to be computed.

    **Example:-**

    modular<1000 * 1000> mod;

    This computes all factorials upto 1000000.

    **Functions:-**

    ncr(): Takes two parameters n, r and computes nCr(n, r).

    Apart from ncr(), there are vectors for fact, inv and invfact, that has factorial, modular inverse and inverse factorial of a number stored in its respective index. 

    Note: modn is the value that you take modulo with and needs to be declared globaly. The _maxval_ that you pass to the structure is not modulo.

* **`SEGMENT TREE (With and without lazy updates):-`**

    segment_tree<_datatype_> tree_name(_vector_, _ORR_value_, _function_);

    _datatype_: The data type to be stored in segment tree.
    _ORR_value_: The value to be returned when the search range is out of required range.
    _function_: The function that segment tree computes.

    **Example:-**
    
    segment_tree<int> st(a, 0, [&](int x, int y) {
        return x + y;
    });

    This creates a segment tree that can be used to compute sum of a segment in array 'a'.

    **Functions:-**

    find(): Takes two parameters l and r, the start and end points of the query, and returns answer for the range l to r (inclusive). It works on 0 based indexing.

    update(): Takes two parameters pos and val, the position to be updated and the value to be assigned and updates the segment tree.

* **`SIEVE :-`**

    sieve<_maxval_> obj_name;

    _maxval_: The value upto which sieve is to be computed.

    **Example:-**

    sieve<10 * 1000 * 1000> s;

    This computes sieve upto 10000000.

    **Functions:-**

    isprime(): Takes one parameter n, and returns true if the number is prime.

    prime_factors(): Takes one parameter n, and returns a vector of pairs, the prime factors of the given number.

    divisors(): Takes one parameter n, and returns a vector of int, the divisors of the given number.   

    prime_divisors(): Takes one parameter n, and returns a vector of int, the prime divisors of the given number.

* **`SPARSE TABLE :-`**

    sparse_table table_name(_function_);

    _function_: The function that sparse table computes. 

    **Example:-**

    sparse_table st([](auto x, auto y) {
        return min(x, y);
    });

    This creates a sparse table for min queries.

    **Functions:-**

    build(): Takes one parameter, the vector on which queries are to be computed and builds the sparse table.

    find(): Takes two parameters l, r, the two endpoints of the query and computes the answer from l to r (inclusive and 0 based indexing)

    find_min(): Similar to find(), used to compute min/max queries in O(1).