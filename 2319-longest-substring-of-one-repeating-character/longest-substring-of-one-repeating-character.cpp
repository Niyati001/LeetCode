class Solution {
    struct Node {
        int len, pref, suff, best;
        char leftChar, rightChar;
    };

    string s;
    vector<Node> tree;
    int n;

    Node merge(Node a, Node b) {
        Node c;
        c.len = a.len + b.len;
        c.leftChar = a.leftChar;
        c.rightChar = b.rightChar;

        bool same = (a.rightChar == b.leftChar);

        c.pref = a.pref;
        if (same && a.pref == a.len)
            c.pref += b.pref;

        c.suff = b.suff;
        if (same && b.suff == b.len)
            c.suff += a.suff;

        c.best = max(a.best, b.best);
        if (same)
            c.best = max(c.best, a.suff + b.pref);

        return c;
    }

    void build(int idx, int l, int r) {
        if (l == r) {
            tree[idx] = {1, 1, 1, 1, s[l], s[l]};
            return;
        }

        int mid = (l + r) / 2;
        build(idx * 2, l, mid);
        build(idx * 2 + 1, mid + 1, r);
        tree[idx] = merge(tree[idx * 2], tree[idx * 2 + 1]);
    }

    void update(int idx, int l, int r, int pos, char c) {
        if (l == r) {
            s[pos] = c;
            tree[idx] = {1, 1, 1, 1, c, c};
            return;
        }

        int mid = (l + r) / 2;
        if (pos <= mid)
            update(idx * 2, l, mid, pos, c);
        else
            update(idx * 2 + 1, mid + 1, r, pos, c);

        tree[idx] = merge(tree[idx * 2], tree[idx * 2 + 1]);
    }

public:
    vector<int> longestRepeating(string s, string queryCharacters,vector<int>& queryIndices) {
        this->s = s;
        n = s.size();
        tree.resize(4 * n);

        build(1, 0, n - 1);

        vector<int> ans;
        for (int i = 0; i < queryIndices.size(); i++) {
            update(1, 0, n - 1, queryIndices[i], queryCharacters[i]);
            ans.push_back(tree[1].best);
        }

        return ans;
    }
};