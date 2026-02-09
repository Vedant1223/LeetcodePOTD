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
    
    void inOrderTraversal(TreeNode* root, vector<int> &v){
        if(root == NULL){
            return;
        }
        inOrderTraversal(root->left, v);

        // processing 
        v.push_back(root->val);

        inOrderTraversal(root->right, v);
    }
    TreeNode* makeTree(vector<int> v, int l , int r){
        if(l>r){
            return NULL;
        }

        int mid = (l+r)/2;
        TreeNode* root = new TreeNode(v[mid]);
        
        root->left = makeTree(v, l, mid-1);
        root->right = makeTree(v, mid+1, r);
        return root;
    }

    TreeNode* balanceBST(TreeNode* root) {
        TreeNode* temp = root;
        vector<int> v;
        inOrderTraversal(temp, v);

        TreeNode* ans = makeTree(v, 0, v.size()-1);
        return ans;
    }
};