template <class T>
struct union_find {
    T *pr, *sz, *cmp, grp;
    constexpr union_find(T n) {
        pr = new T[n + 1];
        sz = new T[n + 1];
        cmp = new T[n + 1];

        for (T i = 1; i < n + 1; i++)
            pr[i] = i, sz[i] = 1, cmp[i] = i;
        grp = n;
    }

    T root(T u) { return pr[u] == u ? u : pr[u] = root(pr[pr[u]]); }
    T find(T u, T v) { return root(u) == root(v); }

    void merge(T u, T v) {
        u = root(u);
        v = root(v);
        if (u == v) return;
        if (sz[u] > sz[v]) swap(u, v);
        pr[u] = v;
        sz[v] += sz[u];
        cmp[u] = cmp[v];
        grp--;
    }
};