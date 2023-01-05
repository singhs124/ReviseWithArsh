class Solution {
    vector<vector<int>> ans ;
public:

    int sum(vector<int> &comb){
        int a = 0;
        for(auto it: comb) a+=it ;
        return a ;
    }

    void fun(int k , int n , vector<int> &comb , int num)
    {
        if(k==0){
            if(sum(comb) == n){
                ans.push_back(comb);
            }
            return ;
        }
        if(num > 9) return ;
        comb.push_back(num) ;
        fun(k-1,n,comb,num+1) ;
        comb.pop_back() ;
        fun(k,n,comb,num+1) ;

    }

    vector<vector<int>> combinationSum3(int k, int n) {
        int num = 1 ;
        vector<int> comb;
        fun(k , n , comb , num) ;
        return ans ;
    }
};
