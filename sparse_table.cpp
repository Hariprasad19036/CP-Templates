struct sparse_table {
    using F = std::function<int(int, int)>;
    int t[maxn][26], LOG[maxn];
    int n;
    F f;

    sparse_table(F f) : f(f) {}

    void build(const vector<int>& a) {
        n = a.size();
        LOG[1] = 0;
        for (int i = 2; i < maxn; i++)
            LOG[i] = LOG[i / 2] + 1;

        for (int i = 0; i < n; i++)
            t[i][0] = a[i];

        for (int j = 1; j < 26; j++)
            for (int i = 0; i + (1 << j) <= n; i++)
                t[i][j] = f(t[i][j - 1], t[i + (1 << (j - 1))][j - 1]);
    }

    int find_min(int l, int r) {
        if (r < l)
            return inf;

        int j = LOG[r - l + 1];
        return f(t[l][j], t[r - (1 << j) + 1][j]);
    }

    int find(int l, int r) {
        if (r < l)
            return inf;
        
        int ans = 0;
        for (int j = 25; j >= 0; j--) {
            if ((1 << j) <= r - l + 1) {
                ans += t[l][j];
                l += (1 << j);
            }
        }
        return ans;
    }
};

sparse_table st([](auto x, auto y) {
    return min(x, y);
});