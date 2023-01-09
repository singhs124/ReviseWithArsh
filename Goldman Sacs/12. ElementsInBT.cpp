//Using Preorder Traversal
class Solution {
public:

    void preorder(TreeNode* root , vector<int> &ans){
        if(!root) return ;
        ans.push_back(root->val) ;
        preorder(root->left,ans);
        preorder(root->right,ans);
    }
    vector<int> getAllElements(TreeNode* root1, TreeNode* root2) {
        vector<int> t1 , t2 ;
        preorder(root1,t1) ;
        preorder(root2,t2) ;
        for(auto it: t2) t1.push_back(it) ;
        sort(t1.begin() , t1.end());
        return t1 ;
    }
};

//Using Stack

class BST{
    public: 
    stack<TreeNode*> s ;
    BST(TreeNode* root){
        pushLeft(root) ;
    }

    void pushLeft(TreeNode* root){
        while(root){
            s.push(root) ;
            root = root->left ;
        }
    }
    bool empty(){
        return s.empty();
    }

    int top(){
        return s.top()->val ;
    }

    int next(){
        auto t = s.top();
        s.pop() ;
        pushLeft(t->right) ;
        return t->val;   
    }
};

class Solution {
public:
    vector<int> getAllElements(TreeNode* root1, TreeNode* root2){
        BST p1(root1) ;
        BST p2(root2) ;
        vector<int> res ;
        while(!p1.empty() && !p2.empty()){
            if(p1.top() <= p2.top()){
                res.push_back(p1.next()) ;
            }
            else res.push_back(p2.next()) ;
        }
        while(!p1.empty()) res.push_back(p1.next()) ;
        while(!p2.empty()) res.push_back(p2.next()) ;

        return res ;
    }
};
