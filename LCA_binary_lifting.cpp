struct lca {
    int n, l, timer;
    vector<int> tin, tout, depth;
    vector<vector<int>> adj, up;

    lca(int n) : n(n), l(ceil(log2(n))) {
        adj.resize(n + 1, vector<int> ());
        up.resize(n + 1, vector<int> (l + 1));
        tin.resize(n + 1);
        tout.resize(n + 1);
        depth.resize(n + 1);
        timer = 0;
    }

    bool is_ancestor(int u, int v) {
        return tin[u] <= tin[v] && tout[u] >= tout[v];
    }

    int dist(int u, int v) {
        return depth[u] + depth[v] - 2 * depth[find(u, v)];
    }

    void dfs(int node, int par, int d = 0) {
        tin[node] = ++timer;
        depth[node] = d;
        up[node][0] = par;
        for (int i = 1; i <= l; i++) {
            up[node][i] = up[up[node][i - 1]][i - 1];
        }

        for (int i : adj[node]) {
            if (i != par) {
                dfs(i, node, d + 1);
            }
        }

        tout[node] = ++timer;
    }

    int find(int u, int v) {
        if (is_ancestor(u, v)) {
            return u;
        }

        if (is_ancestor(v, u)) {
            return v;
        }

        for (int i = l; i >= 0; i--) {
            if (!is_ancestor(up[u][i], v)) {
                u = up[u][i];
            }
        }

        return up[u][0];
    }
};