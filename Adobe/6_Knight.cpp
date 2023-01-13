class Solution {
public:
    
    
    double dp[26][26][101]  ;

    
    double knightProbability(int n, int k, int r, int c) {
        
        for(int i = 0 ; i < r ; i++){
            for(int j = 0 ; j < c ; j++){
                dp[i][j][0] = 1 ;
                for(int m = 1 ; m <= k ; m++){
                    double sum = 0 ;
                    int dr[8] = {-1,-2,-2,-1,1,2,2,1};
                    int dc[8] = {-2,-1,1,2,2,1,-1,-2};
                    for(int h = 0 ; h < 8 ; h++){
                        int nr = i+dr[h] ;
                        int nc = j+dc[h] ;
                        if(nr>=0 && nc>=0 && nr < n && nc<n)
                            sum += dp[nr][nc][m-1] ;
                    }
                    sum /= 8 ;
                    dp[i][j][m] = sum ;
                }
            }
        }
        
        return ans ;
    }
    
};
