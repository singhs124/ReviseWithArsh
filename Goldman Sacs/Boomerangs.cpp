class Solution {
public:
    int numberOfBoomerangs(vector<vector<int>>& p) {
        int n = p.size() ;
        int ans = 0 ;
        for(int i = 0 ; i < n ; i++){
            unordered_map<int, int> m ;
            for(int j = 0 ; j < n ; j++){
                if(j == i) continue ;

                int dy = p[j][1] - p[i][1] ;
                int dx = p[j][0] - p[i][0] ;

                int val = dy*dy + dx*dx ;

                m[val]++;
            }
            for(auto it: m){
                if(it.second > 1){
                    ans += it.second * (it.second-1) ;
                }
            }
        }
        return ans ;
    }
};
