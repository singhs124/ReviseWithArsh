class Solution {
public:
    int dirs[4][2] = {{0,1},{0,-1},{1,0},{-1,0}};
    bool dfs(int t , vector<vector<int>>& grid , int i , int j , vector<vector<int>>& vis){
        int n = grid.size() ;
        if(i==n-1 && j == n-1) return true ;
        vis[i][j] = true ;
        for(auto it: dirs){
            int nr = i + it[0] , nc = j + it[1] ;
            if(nr>=0 && nc>=0 && nr<n && nc<n && !vis[nr][nc] && grid[i][j] <= t && grid[nr][nc] <= t){
                if(dfs(t,grid,nr,nc,vis)) return true ;
            }
        }
        return false;
    }

    int swimInWater(vector<vector<int>>& grid) {
        int n = grid.size() ;
        int low = 0 , high = n*n-1 ;

        while(low < high){
            int mid = (low+high)/2 ;
            vector<vector<int>> vis(n,vector<int>(n,0));
            if(dfs(mid,grid,0,0,vis)) high = mid ;
            else low = mid+1 ;
        }
        return low ;
    }
};
