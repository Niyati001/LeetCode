/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    int dfs(TreeNode* root, int maxSoFar){
        if(root== NULL) return 0;
        int count=0;

        if(root-> val>= maxSoFar)
            count=1;

        maxSoFar= max(root-> val, maxSoFar);

        count+= dfs(root-> left, maxSoFar);
        count+= dfs(root-> right, maxSoFar);

        return count;
    }

    int goodNodes(TreeNode* root) {
        int count=0;

        return dfs(root, root-> val);
    }
};