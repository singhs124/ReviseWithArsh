class Solution {
public:
    int area = 0 ;
    void dfs(int r , int c , vector<vector<int>>& grid,int &one){
        int n = grid.size() ;
        int m = grid[0].size() ;

        grid[r][c] = 2 ;

        int dr[4] = {-1,0,1,0};
        int dc[4] = {0,-1,0,1};

        for(int i = 0 ; i < 4 ; i++){
            int nr = r+dr[i] ;
            int nc = c+dc[i] ;
            if(nr>=0 && nc>=0 && nr<n && nc<m && grid[nr][nc] == 1){
                one++;
                dfs(nr,nc,grid,one) ;
            }
        }
    }

    int maxAreaOfIsland(vector<vector<int>>& grid) {
        
        int n = grid.size() ;
        int m = grid[0].size() ;
        int count = 0 ;
        for(int i = 0 ; i < n ; i++){
            for(int j = 0 ; j < m ; j++){
                if(grid[i][j] == 1){
                    int one = 1;
                    dfs(i,j,grid,one);
                    area = max(area,one);
                }
            }
        }
        return area ;
    }
    
};
