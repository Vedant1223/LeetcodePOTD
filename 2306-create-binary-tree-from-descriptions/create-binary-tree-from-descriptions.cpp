/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left),
 * right(right) {}
 * };
 */
class Solution {
public:
    TreeNode* createBinaryTree(vector<vector<int>>& desc) {
        unordered_map<int, TreeNode*> mp;
        unordered_set<int> children;
        int root = desc[0][0];

        for (int i = 0; i < desc.size(); i++) {
            
            vector<int> v = desc[i];
            int parent = v[0];
            int child = v[1];
            children.insert(child);


            TreeNode* par = NULL;
            if (mp.find(parent) == mp.end()) {
                par = new TreeNode(parent);
            } else {
                par = mp[parent];
            }

            TreeNode* ch = NULL;
            if (mp.find(child) == mp.end()) {
                ch = new TreeNode(child);
            } else {
                ch = mp[child];
            }

            if (v[2] & 1) {
                par->left = ch;
            } else {
                par->right = ch;
            }

            mp[child] = ch;
            mp[parent] = par;
        }

        for(int i = 0; i< desc.size(); i++){
            if(children.find(desc[i][0]) == children.end()){
                root = desc[i][0];
            }
        }

        return mp[root];
    }
};