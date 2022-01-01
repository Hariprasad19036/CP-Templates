template<typename T>
struct Centroid {
    vector<T> adj[maxn];
    vector<T> sz;
    vector<bool> dead;

    Centroid(int n) {
        clear(n);
    }

    void clear(int n) {
        dead.assign(n + 1, 0);
        sz.assign(n + 1, 1);
        for (int i = 0; i <= n; i++) {
            adj[i].clear();
        }
    }

    vector<T> centroid(T root) {
        function<void(T, T)> get_sz = [&](T node, T par) {
            sz[node] = 1;
            for (auto i : adj[node]) {
                if (i != par && !dead[i]) {
                    get_sz(i, node);
                    sz[node] += sz[i];
                }
            }
        };

        get_sz(root, -1);
        int n = sz[root];
        vector<T> res;
        function<void(T, T)> dfs = [&](T node, T par) {
            bool ok = true;
            for (auto i : adj[node]) {
                if (i != par && !dead[i]) {
                    dfs(i, node);
                    ok &= (sz[i] <= n / 2);
                }
            }

            ok &= ((n - sz[node]) <= n / 2);
            if (ok) res.push_back(node);
        };
        dfs(root, -1);

        return res;
    }

    void decompose() {
        function<void(T, T)> rec = [&](T start, T d) {
            T x = centroid(start)[0];
            dead[x] = true;
            for (auto i : adj[x]) {
                if (!dead[i]) {
                    rec(i, d + 1);
                }
            }

            dead[x] = false; 
        };

        rec(1, 0);
    }
};