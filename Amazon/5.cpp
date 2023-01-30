class Solution {
public:
    int maxSum(vector<vector<int>>& grid) {
        int n = grid.size() ;
        int m = grid[0].size() ;

        for(auto &it: grid){
            for(int i = 1 ; i < it.size() ;i++){
                it[i] = it[i] + it[i-1] ;
            }
        }
        int res = INT_MIN ; 
        for(int i = 2 ; i < n ; i++){
            for(int j = 2 ; j < m ; j++)
            {
                int ans = grid[i][j] + grid[i-2][j] + grid[i-1][j-1] - grid[i-1][j-2] ;
                if(j-3>=0) ans -= (grid[i][j-3] + grid[i-2][j-3]) ; 
                res = max(res,ans) ;
            }
        }
        return res ;
    }
};
