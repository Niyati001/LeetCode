/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Codec {
public:
    void preOrder(TreeNode* root, string &s){
        if(root== NULL){
            s+= "#,";
            return;
        }
        
        s+= to_string(root-> val);
        s+= ",";

        preOrder(root-> left, s);
        preOrder(root-> right, s);
    }

    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        string s;
        preOrder(root, s);
        
        return s;
    }
    
    TreeNode* build(stringstream &ss){
        string val;
        getline(ss, val, ',');

        if(val== "#")
            return NULL;
        
        TreeNode* root= new TreeNode(stoi(val));

        root-> left= build(ss);
        root-> right= build(ss);

        return root;
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        stringstream ss(data);

        return build(ss);
    }
};

// Your Codec object will be instantiated and called as such:
// Codec ser, deser;
// TreeNode* ans = deser.deserialize(ser.serialize(root));