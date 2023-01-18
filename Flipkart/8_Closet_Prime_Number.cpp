class Solution {
public:
    vector<int> closestPrimes(int left, int right) {
        vector<bool> prime(right+1,true) ;
        vector<int> ans;
        int mini = INT_MAX;
        for(int i = 2 ; i <= right ; i++){
            if(prime[i]){
                for(int j = i*2 ; j <= right ; j+=i){
                    prime[j] = false ;
                }
            }
        }
        prime[0] = false;
        prime[1] = false ;
        for(int i = left ; i <= right ; i++){
            if(prime[i]) ans.push_back(i) ;
        }
        vector<int> res ;
        if(ans.size() <= 1) return {-1,-1} ;
        for(int i = 1 ; i < ans.size() ; i++){
            if(ans[i]-ans[i-1] < mini){
                res.clear() ;
                mini = ans[i]-ans[i-1] ;
                res.push_back(ans[i-1]);
                res.push_back(ans[i]) ; 
            }
            if(mini <= 2) break;
        }
        return res ;

    }
};
