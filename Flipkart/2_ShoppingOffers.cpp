//Wrong Submission
class Solution {
public:
    int shoppingOffers(vector<int>& price, vector<vector<int>>& special, vector<int>& needs) {
        int res = INT_MAX ;
        int n = needs.size() ;
        for(auto it: special){
            vector<int> offer = it ;
            vector<int> dummy(n) ;
            bool flag = true ;
            int ans = -1 ;
            for(int j = 0 ; j < offer.size()-1 ; j++){
                if(offer[j] > needs[j]){
                    flag = false;
                    break;
                }
                dummy[j] = needs[j] - offer[j] ;
            }
            if(flag){
                ans = offer[offer.size()-1]  ;
                for(int i = 0 ; i < n ; i++){
                    ans += dummy[i]*price[i] ;
                }
            }
            if(ans != -1)
                res = min(res,ans) ;
        }
        long long c = 0 ;
        for(int i = 0 ; i < n ; i++){
            int a = needs[i] ;
            int b = price[i] ;
            c += a*b ;
        }
        res = min(res , int(c));
        return res ;
    }
};

//TLE

class Solution {
public:
    int shoppingOffers(vector<int>& price, vector<vector<int>>& special, vector<int>& needs) {
        int local_min = sum(price,needs) ;
        vector<int> tmp ;
        for(auto it : special){
            tmp.clear() ;
            for(int j = 0 ; j < needs.size() ; j++){
                if(it[j] > needs[j]){
                    tmp.clear() ;
                    break;
                }
                tmp.push_back(needs[j] - it[j]) ;
            }
            if(!tmp.empty()){
                local_min = min(local_min , it.back() + shoppingOffers(price , special,tmp)) ;
            }
        }
        return local_min;

    }
    int sum(vector<int> price , vector<int> needs){
        int ans = 0;
        for(int i = 0 ; i < price.size() ; i++){
            ans += price[i]*needs[i] ;
        }
        return ans ;
    }
};

