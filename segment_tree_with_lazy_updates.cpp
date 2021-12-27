template<typename T>
struct segment_tree {
    using F = std::function<T(const T&, const T&)>;
    int n;
    T e;
    F f;
    std::vector<T> t, lazy;

    segment_tree(const std::vector<T> &a, T e, F f) : n(a.size()), lazy(4 * a.size()), e(e), t(4 * a.size()), f(f) {
        build(a, 1, 0, n - 1);
    }

    void build(const std::vector<T> &a, int v, int tl, int tr) {
        if (tl == tr) {
            t[v] = T(a[tl]);
        }
        else {
            int tm = (tl + tr) / 2;
            build(a, v << 1, tl, tm);
            build(a, v << 1 | 1, tm + 1, tr);
            t[v] = f(t[v << 1], t[v << 1 | 1]);
        }
    }

    void push(int v) {
        t[v << 1] = f(t[v << 1], lazy[v]);
        t[v << 1 | 1] = f(t[v << 1 | 1], lazy[v]);
        lazy[v << 1] = f(lazy[v << 1], lazy[v]);
        lazy[v << 1 | 1] = f(lazy[v << 1 | 1], lazy[v]);
        lazy[v] = e;
    }

    T find_helper(int v, int tl, int tr, int l, int r) {
        if (l > r)
            return e;
        if (l <= tl && r >= tr)
            return t[v];
        push(v);
        int tm = (tl + tr) / 2;
        return f(find_helper(v << 1, tl, tm, l, min(r, tm)), find_helper(v << 1 | 1, tm + 1, tr, max(l, tm + 1), r));
    }

    T find(int l, int r) {
        return find_helper(1, 0, n - 1, l, r);
    }

    void update_helper(int v, int tl, int tr, int l, int r, T val) {
        if (tr < l || r < tl)
            return;

        if (l <= tl && r >= tr) {
            t[v] = f(t[v], val);
            lazy[v] = f(lazy[v], val);
        }
        else {
            push(v);
            int tm = (tl + tr) >> 1;
            update_helper(v << 1, tl, tm, l, min(r, tm), val);
            update_helper(v << 1 | 1, tm + 1, tr, max(l, tm + 1), r, val);
            t[v] = f(t[v << 1], t[v << 1 | 1]);
        }
    }

    void update(int l, int r, T val) {
        update_helper(1, 0, n - 1, l, r, val);
    }
};