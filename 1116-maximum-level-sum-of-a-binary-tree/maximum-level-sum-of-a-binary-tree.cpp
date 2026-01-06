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
    int maxLevelSum(TreeNode* root) {
        queue<TreeNode*> q;
        q.push(root);
        q.push(NULL);
        int sum = 0;
        int maxi = INT_MIN;
        int maxLevel = 0;
        int level = 1;

        while(!q.empty()){
            
            TreeNode* f = q.front();
            q.pop();

            if(f == NULL){
                if(maxi < sum){
                    maxi = sum;
                    maxLevel = level;
                }
                level++;
                sum = 0;
                // null dal rkha h
                if( !q.empty()){
                    q.push(NULL); 
                }
            }
            else{
                sum += f->val;
                if(f->left){
                    q.push(f->left);
                }
                if(f->right){
                    q.push(f->right);
                }
            }
        }

        return maxLevel;
    }
};