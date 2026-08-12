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
    unordered_map<int, int> inMap;
    int postIndex;
    
    TreeNode* build(vector<int>& inorder, vector<int>& postorder, int inStart, int inEnd){
        if(inStart> inEnd) return NULL;

        int rootVal= postorder[postIndex--];
        TreeNode* root= new TreeNode(rootVal);

        int inIndex= inMap[rootVal];

        root-> right= build(inorder, postorder, inIndex+1, inEnd);
        root->left= build(inorder, postorder, inStart, inIndex-1);

        return root;
    }

    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        inMap.clear();
        postIndex= postorder.size()-1;

        for(int i=0; i<inorder.size(); i++){
            inMap[inorder[i]]=i;
        }
        return build(inorder, postorder, 0, inorder.size()-1);
    }
};