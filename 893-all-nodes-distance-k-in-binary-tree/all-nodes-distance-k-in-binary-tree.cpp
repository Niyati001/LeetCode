
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

class Solution {
public:
    unordered_map<TreeNode*, TreeNode*> parent;

    void buildParent(TreeNode* node, TreeNode* par) {
        if (!node) return;

        parent[node] = par;

        buildParent(node->left, node);
        buildParent(node->right, node);
    }

    vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {
        buildParent(root, nullptr);

        queue<TreeNode*> q;
        unordered_set<TreeNode*> visited;

        q.push(target);
        visited.insert(target);

        int distance = 0;

        while (!q.empty()) {
            int sz = q.size();

            if (distance == k) {
                vector<int> ans;

                while (!q.empty()) {
                    ans.push_back(q.front()->val);
                    q.pop();
                }

                return ans;
            }

            while (sz--) {
                TreeNode* node = q.front();
                q.pop();

                vector<TreeNode*> neighbors = {
                    node->left,
                    node->right,
                    parent[node]
                };

                for (TreeNode* next : neighbors) {
                    if (next && !visited.count(next)) {
                        visited.insert(next);
                        q.push(next);
                    }
                }
            }

            distance++;
        }

        return {};
    }
};
