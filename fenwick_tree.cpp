template <typename T>
struct fenwick_tree {
    using F = std::function<T(T, T)>;
    int n;
    F f;
    std::vector<T> bit;

    fenwick_tree(int n, F f = std::plus<T> ()) : n(n), f(f) {
        bit.assign(n + 1, 0);
    }

    void update(int idx, T value) {
        for (; idx < n; idx |= (idx + 1))
            bit[idx] = f(bit[idx], value);
    }

    T compute(int r) {
        T ans = 0;
        for (; r >= 0; r = (r & (r + 1)) - 1)
            ans = f(ans, bit[r]);

        return ans;
    }
};