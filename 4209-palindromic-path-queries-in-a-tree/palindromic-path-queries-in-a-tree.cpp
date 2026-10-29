class Solution {
public:
    vector<vector<int>> adj;
    vector<int> parent, depth, heavy, head, pos, subtree;
    vector<int> seg;
    string s;
    int timer;

    int bit(char c) {
        return 1 << (c - 'a');
    }

    int dfs(int u, int p) {
        parent[u] = p;
        subtree[u] = 1;
        int maxSize = 0;

        for (int v : adj[u]) {
            if (v == p) continue;

            depth[v] = depth[u] + 1;
            int size = dfs(v, u);
            subtree[u] += size;

            if (size > maxSize) {
                maxSize = size;
                heavy[u] = v;
            }
        }

        return subtree[u];
    }

    void decompose(int u, int h) {
        head[u] = h;
        pos[u] = timer++;

        if (heavy[u] != -1)
            decompose(heavy[u], h);

        for (int v : adj[u]) {
            if (v == parent[u] || v == heavy[u])
                continue;

            decompose(v, v);
        }
    }

    void build(int node, int l, int r) {
        if (l == r) {
            seg[node] = bit(sNode[l]);
            return;
        }

        int mid = (l + r) / 2;
        build(node * 2, l, mid);
        build(node * 2 + 1, mid + 1, r);

        seg[node] = seg[node * 2] ^ seg[node * 2 + 1];
    }

    vector<char> sNode;

    void update(int node, int l, int r, int idx, int value) {
        if (l == r) {
            seg[node] = value;
            return;
        }

        int mid = (l + r) / 2;

        if (idx <= mid)
            update(node * 2, l, mid, idx, value);
        else
            update(node * 2 + 1, mid + 1, r, idx, value);

        seg[node] = seg[node * 2] ^ seg[node * 2 + 1];
    }

    int query(int node, int l, int r, int ql, int qr) {
        if (ql <= l && r <= qr)
            return seg[node];

        if (r < ql || l > qr)
            return 0;

        int mid = (l + r) / 2;

        return query(node * 2, l, mid, ql, qr) ^ query(node * 2 + 1, mid + 1, r, ql, qr);
    }

    int pathMask(int u, int v, int n) {
        int mask = 0;

        while (head[u] != head[v]) {
            if (depth[head[u]] < depth[head[v]])
                swap(u, v);

            mask ^= query(1, 0, n - 1, pos[head[u]], pos[u]);

            u = parent[head[u]];
        }

        if (depth[u] > depth[v])
            swap(u, v);

        mask ^= query(1, 0, n - 1, pos[u], pos[v]);

        return mask;
    }


    vector<bool> palindromePath(int n, vector<vector<int>>& edges, string s, vector<string>& queries) {
        adj.assign(n, {});

        for (auto& e : edges) {
            adj[e[0]].push_back(e[1]);
            adj[e[1]].push_back(e[0]);
        }

        parent.assign(n, -1);
        depth.assign(n, 0);
        heavy.assign(n, -1);
        head.assign(n, 0);
        pos.assign(n, 0);
        subtree.assign(n, 0);
        timer = 0;

        dfs(0, -1);
        decompose(0, 0);

        sNode.resize(n);
        for (int u = 0; u < n; u++)
            sNode[pos[u]] = s[u];

        seg.assign(4 * n, 0);
        build(1, 0, n - 1);

        vector<bool> answer;

        for (string& q : queries) {
            string type;
            int u, v;
            char c;

            stringstream ss(q);
            ss >> type;

            if (type == "update") {
                ss >> u >> c;
                s[u] = c;

                update(1, 0, n - 1, pos[u], bit(c));
            } 
            
            else {
                ss >> u >> v;

                int mask = pathMask(u, v, n);

                answer.push_back((mask & (mask - 1)) == 0);
            }
        }

        return answer;
    }
};