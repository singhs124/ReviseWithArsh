class Solution {
public:
    int maxConsecutive(int bottom, int top, vector<int>& special) {
        int n = special.size() ;
        int res = 0;
        sort(special.begin() , special.end()) ;
        for(int i = 0 ; i < n ; i++){
            if(i==0){
                res = max(res , special[i]-bottom) ;
            }
            else res = max(res , special[i]-special[i-1]-1) ;
        }
        res = max(res , top-special[n-1]) ;

        return res ;
    }
};
