# CP-Templates
A Collection of Templates for different data structures that I use in Competitive programming.

## Usage:
> SEGMENT TREE (With and without lazy updates):-
    
    segment_tree<_datatype_> tree_name(_vector_, _ORR_value_, _function_);

    _datatype_: The data type to be stored in segment tree.
    _ORR_value_: The value to be returned when the search range is out of required range.
    _function_: The function that segment tree computes.

    Example:-
    segment_tree<int> st(a, 0, [&](int x, int y) {
        return x + y;
    });

    This creates a segment tree that can be used to compute sum of a segment in array 'a'.

> FENWICK TREE :-

    fenwick_tree<_datatype_> tree_name(_size_, _function_);

    _datatype_: The data type to be stored in fenwick tree.
    _size_: Size of the fenwick tree.
    _function_: The function that fenwick tree computes. It is an optional Parameter. By default, fenwick tree is created to compute sum queries.

    Example:-
    fenwick_tree<int> ft(n);

    This creates a fenwick tree of size n + 1 for sum queries.

    fenwick_tree<int> ft(n, [&](int x, int y) {
        return min(x, y);
    });

    This creates a fenwick tree of size n + 1 for min queries.