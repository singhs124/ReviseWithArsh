class Solution {
public:

    bool dfs(int r , int c , vector<vector<int>>& grid){
        int n = grid.size() ;
        int m = grid[0].size() ;
        if(r<0 || c<0 || r>=n || c>=m) return false ;
        if(grid[r][c] == 2 || grid[r][c] == 1) return true ;
        grid[r][c] = 2 ;
        bool up = dfs(r-1,c,grid) ;
        bool down = dfs(r+1,c,grid) ;
        bool right = dfs(r,c+1,grid) ;
        bool left = dfs(r,c-1 ,grid) ;
        return up && down && right && left ;
    }

    int closedIsland(vector<vector<int>>& grid) {
        int n = grid.size() ;
        int m = grid[0].size() ;
        int ans = 0 ;
        for(int i = 1 ; i < n-1 ; i++){
            for(int j = 1 ; j < m-1 ; j++){
                if(grid[i][j] == 0){
                    if(dfs(i,j,grid)) ans++ ;
                }
            }
        }
        return ans ;
    }
};
