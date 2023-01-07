//2 pass Solution
class Solution {
public:
    int minimumCardPickup(vector<int>& c) {
        int n = c.size() ;
        int ans = INT_MAX;
        map<int,vector<int>> m ;
        for(int i = 0 ; i < n ; i++){
            m[c[i]].push_back(i) ;
        }
        for(auto it : m){
            if(it.second.size() > 1){
                auto v = it.second ;
                for(int i = 0 ; i < v.size()-1 ; i++){
                    ans = min(ans , v[i+1]-v[i]+1) ;
                }
            }
        }
        return ans == INT_MAX? -1 : ans ;
    }
};

//1 Pass Solution

class Solution {
public:
    int minimumCardPickup(vector<int>& c) {
        int n = c.size() ;
        int ans = INT_MAX ;
        unordered_map<int,int> m ;

        for(int i = 0 ; i < n ; i++){
            if(m.find(c[i]) != m.end()){
                ans = min(ans , i-m[c[i]]+1) ;
            }
            m[c[i]] = i ;
        }
        return ans == INT_MAX ? -1:ans ;
    }
};
