//Memo
class Solution {
public:

    int fun(TreeNode* root , unordered_map<TreeNode* , int> &m){
        if(!root) return 0 ;
        if(m.find(root) != m.end()) return m[root] ;
        int sum = 0 ;
        if(root->left) sum+= fun(root->left->left , m) + fun(root->left->right , m) ;
        if(root->right) sum += fun(root->right->left , m) + fun(root->right->right , m) ;

        return m[root] = max(sum+root->val ,fun(root->left , m)+fun(root->right , m)) ;
    }

    int rob(TreeNode* root) {
        unordered_map<TreeNode* , int> m ;
        return fun(root , m) ;
    }
};


//Optimized
class Solution {
public:
    int rob(TreeNode* root) {
        auto ans = fun(root) ;
        return max(ans.first , ans.second) ;
    }

    pair<int,int> fun(TreeNode* root){
        if(!root) return {0,0} ;
        auto [leftNoRob , leftRob] = fun(root->left) ;
        auto [rightNoRob , rightRob] = fun(root->right) ;


        return {
            max(leftNoRob,leftRob) + max(rightNoRob , rightRob) ,
            root->val + leftNoRob + rightNoRob 
        };
    }
};
