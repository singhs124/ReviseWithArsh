class Solution {
public:
    vector<int> a ; 
    Solution(vector<int>& w) {
       for(auto it: w){
           if(a.empty()) a.push_back(it) ;
           else a.push_back(it+a.back()) ;
       }
    }
    
    int pickIndex() {
        int num = a.back() ;
        int r = rand()%num ;
        auto res = upper_bound(a.begin() , a.end() , r) ;
        return res-a.begin() ;
    }
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(w);
 * int param_1 = obj->pickIndex();
 */
