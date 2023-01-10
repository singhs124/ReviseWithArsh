class Solution {
public:
    int maxPoints(vector<vector<int>>& arr) {
        int ans = 1 ;
        int n = arr.size() ;
        for(int i = 0 ; i <n ; i++){
            unordered_map<double,int> m ;
            for(int j = i+1 ; j < n ; j++){
                double x = double(arr[j][1] - arr[i][1])/double(arr[j][0] - arr[i][0]) ;
                if(arr[j][0] - arr[i][0] == 0) m[abs(x)]++;
                else m[x]++ ;
            }
            int temp = 0 ;
            for(auto it: m){
                temp = max(temp , it.second+1) ;
            }
            ans = max(ans,temp) ;
        }
        return ans ;
        
    }
};
