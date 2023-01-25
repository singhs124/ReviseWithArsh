class Solution {
public:
int n , m ;
    int fun(int i , int j , vector<vector<int>> &sum){
        if(i<0 || j<0) return 0;
        if(i>=n) i = n-1 ;
        if(j>=m) j = m-1 ;
        return sum[i][j] ;
    } 

    vector<vector<int>> matrixBlockSum(vector<vector<int>>& mat, int k) {
        n = mat.size() ;
        m = mat[0].size() ;

        vector<vector<int>> sum(n, vector<int>(m, 0));
        for(int i = 0 ; i < n ; i++){
            for(int j = 0 ; j < m ; j++){
                sum[i][j] = mat[i][j] + fun(i,j-1,sum) + fun(i-1,j,sum) - fun(i-1,j-1,sum) ;
            }
        }

        for(int i = 0 ; i < n ; i++){
            for(int j = 0 ; j < m ; j++){
                mat[i][j] = fun(i+k,j+k,sum) - fun(i+k,j-k-1,sum) - fun(i-k-1,j+k,sum) + fun(i-k-1,j-k-1,sum) ;
            }
        }
        return mat ;
    }
};
