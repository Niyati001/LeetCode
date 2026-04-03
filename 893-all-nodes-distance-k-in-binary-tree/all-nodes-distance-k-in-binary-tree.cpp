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
    void markParent(TreeNode* root, unordered_map<TreeNode*, TreeNode*>&parent){
        queue<TreeNode*> q;
        q.push(root);

        while(!q.empty()){
            TreeNode* node= q.front();
            q.pop();

            if(node-> left){
                parent[node-> left]= node;
                q.push(node-> left);
            }
            if(node-> right){
                parent[node-> right]= node;
                q.push(node-> right);
            }
        }
    }
    vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {
        unordered_map<TreeNode*, TreeNode*> parent;
        markParent(root, parent);

        TreeNode* targetNode= NULL;
        queue<TreeNode*> q;
        q.push(root);

        while(!q.empty()){
            TreeNode* node= q.front();
            q.pop();

            if(node== target){
                targetNode= node;
            }
            if(node-> left)q.push(node-> left);
            if(node-> right) q.push(node-> right);
        }

        unordered_map<TreeNode*, bool> visited;
        queue<TreeNode*> qq;

        qq.push(targetNode);
        visited[targetNode]= true;

        int curLevel=0;

        while(!qq.empty()){
            int size= qq.size();

            if(curLevel== k) break;
            curLevel++;

            for(int i=0; i<size; i++){
                TreeNode* node= qq.front();
                qq.pop();

                if(node-> left && !visited[node-> left]){
                    qq.push(node->left);
                    visited[node-> left]= true;                
                }

                if(node-> right && !visited[node-> right]){
                    qq.push(node-> right);
                    visited[node-> right]= true;
                }

                if(parent[node] && !visited[parent[node]]){
                    qq.push(parent[node]);
                    visited[parent[node]]= true;
                }
            }
        }

        vector<int> ans;
        while(!qq.empty()){
            ans.push_back(qq.front()-> val);
            qq.pop();
        }
        sort(ans.begin(), ans.end());
        return ans;
    }
};