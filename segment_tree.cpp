template<typename T>
struct segment_tree {
    using F = std::function<T(T, T)>;
    int n;
    T e;
    F f;
    std::vector<T> t;

    template<typename U>
    segment_tree(const std::vector<U> &a, T e, F f) : n(a.size()), e(e), t(4 * a.size()), f(f) {
        build(a, 1, 0, n - 1);
    }

    template<typename U>
    T create(U x) {
        return T(x);
    }

    template<typename U>
    void build(const std::vector<U> &a, int v, int tl, int tr) {
        if (tl == tr) {
            t[v] = create(a[tl]);
        }
        else {
            int tm = (tl + tr) / 2;
            build(a, v << 1, tl, tm);
            build(a, v << 1 | 1, tm + 1, tr);
            t[v] = f(t[v << 1], t[v << 1 | 1]);
        }
    }

    T find_helper(int v, int tl, int tr, int l, int r) {
        if (l > r)
            return e;
        if (l == tl && r == tr)
            return t[v];
        int tm = (tl + tr) / 2;
        return f(find_helper(v << 1, tl, tm, l, min(r, tm)), find_helper(v << 1 | 1, tm + 1, tr, max(l, tm + 1), r));
    }

    T find(int l, int r) {
        return find_helper(1, 0, n - 1, l, r);
    }

    void update_helper(int v, int tl, int tr, int pos, T val) {
        if (tl == tr) {
            t[v] = val;
        }
        else {
            int tm = (tl + tr) / 2;
            if (pos <= tm)
                update_helper(v << 1, tl, tm, pos, val);
            else
                update_helper(v << 1 | 1, tm + 1, tr, pos, val);
            t[v] = f(t[v << 1], t[v << 1 | 1]);
        }
    }

    void update(int pos, T val) {
        update_helper(1, 0, n - 1, pos, val);
    }
};