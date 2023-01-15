class Solution {
public:
    int mod = 1e9 + 7 ;
    long long fun(int n, int d, int f, vector<long long> &dp){
        if(!n) return 0 ;
        if(dp[n] !=-1) return dp[n] ;
        long long res = 1;
        for(int i = d ; i < f ; i++){
            if(n-i>=0)
                res = (res + fun(n-i,d,f,dp))%mod  ;
        }
        return dp[n] = res%mod ;
    }

    int peopleAwareOfSecret(int n, int delay, int forget) {
        vector<long long> dp(n+1,-1) ;
        return (fun(n,delay,forget,dp) - fun(n-forget,delay,forget,dp) + mod)%mod ;
    }
};
