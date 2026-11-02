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
    int prev=0;
    int count= 0;
    int maxCount=0;
    vector<int> ans;

    void inorder(TreeNode* root){
        if(root== nullptr)
           return;

        inorder(root-> left);

        if(count==0 || root-> val!= prev)
            count=1;
        else
            count++;

        if(count> maxCount){
            maxCount= count;
            ans.clear();
            ans.push_back(root-> val);
        }

        else if(count== maxCount)
           ans.push_back(root-> val);

        prev= root-> val;
        inorder(root-> right);
    }

    vector<int> findMode(TreeNode* root) {
        inorder(root);

        return ans;
    }
};