class Solution {
public:
int mod = 1e9+7 ;
    int fun(int s , int e , int k , vector<vector<int>> &dp){
        if(k==0) return s==e ;
        if(abs(e-s) > k) return 0 ;
        if(dp[s+1000][k] != -1) return dp[s+1000][k] % mod;
        int left = fun(s-1,e,k-1,dp)%mod;
        int right = fun(s+1,e,k-1,dp)%mod;
        return dp[s+1000][k] = (left+right)%mod ;
    }

    int numberOfWays(int s, int e, int k) {
        vector<vector<int>> dp(3002 , vector<int>(k+1,-1)) ;
        for(int i = 0 ; i < s ; i++) dp[s][0] = 0 ;
        return fun(startPos,endPos,k,dp) ;
    }
};
