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
    int count = 0;
    // pair<int,int>  ----> root->data , count
    pair<int,int> fun(TreeNode* root){
        if(!root) return {0,0} ;
        if(!root->left && !root->right){
            count++ ;
            return {root->val , 1} ;
        } 
        auto l = fun(root->left) ;
        auto r = fun(root->right) ;
        int num = root->val + l.first + r.first ;
        int den = 1 + l.second + r.second;
        int avg = num/den ;
        if(avg == root->val) count++;
        return {num,den} ;
    }

    int averageOfSubtree(TreeNode* root) {
        fun(root) ;
        return count ;
    }
};
