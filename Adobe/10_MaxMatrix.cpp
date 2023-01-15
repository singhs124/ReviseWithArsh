class Solution {
public:
    long long maxMatrixSum(vector<vector<int>>& m) {
        long long sum = 0;
        int n = m.size() ;
        int negative = 0 ;
        int mini = 1e9+7 ;
        for(int i = 0 ; i < n ; i++){
            for(int j = 0 ; j < n ; j++){
                sum += abs(m[i][j]) ;
                if(m[i][j] < 0) negative++ ;
                mini = min(mini,abs(m[i][j])) ;
            }
        }
        if(negative%2){
            sum = sum - mini + (-1*mini) ;
        }
        return sum ;
    }
};
