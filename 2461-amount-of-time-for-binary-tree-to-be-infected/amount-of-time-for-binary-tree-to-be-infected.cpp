class Solution {
public:
    unordered_map<TreeNode*, TreeNode*> parent;

    void makeParent(TreeNode* root) {
        if (root == nullptr)
            return;

        if (root->left != nullptr) {
            parent[root->left] = root;
            makeParent(root->left);
        }

        if (root->right != nullptr) {
            parent[root->right] = root;
            makeParent(root->right);
        }
    }

    TreeNode* findStart(TreeNode* root, int start) {
        if (root == nullptr)
            return nullptr;

        if (root->val == start)
            return root;

        TreeNode* left = findStart(root->left, start);

        if (left != nullptr)
            return left;

        return findStart(root->right, start);
    }

    int amountOfTime(TreeNode* root, int start) {
        // Store parent of every node
        makeParent(root);

        // Find starting node
        TreeNode* startNode = findStart(root, start);

        queue<TreeNode*> q;
        unordered_set<TreeNode*> visited;

        q.push(startNode);
        visited.insert(startNode);

        int minutes = -1;

        while (!q.empty()) {
            int size = q.size();
            minutes++;

            while (size--) {
                TreeNode* node = q.front();
                q.pop();

                // Left
                if (node->left &&
                    !visited.count(node->left)) {

                    visited.insert(node->left);
                    q.push(node->left);
                }

                // Right
                if (node->right &&
                    !visited.count(node->right)) {

                    visited.insert(node->right);
                    q.push(node->right);
                }

                // Parent
                if (parent.count(node) &&
                    !visited.count(parent[node])) {

                    visited.insert(parent[node]);
                    q.push(parent[node]);
                }
            }
        }

        return minutes;
    }
};