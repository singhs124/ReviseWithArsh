class Solution {
public:
    int getLastMoment(int n, vector<int>& left, vector<int>& right) {
        int res = 0;
        for(auto it: left) res = max(res,it) ;
        for(auto it: right) res = max(res,n-it) ;
        return res ;
    }
};
