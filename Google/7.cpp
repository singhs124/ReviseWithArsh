class Solution {
public:
    int countDistinct(vector<int>& nums, int k, int p) {
        int n = nums.size() ;
        unordered_map<string,int> m ;

        for(int i = 0 ; i < n ; i++){
            int cnt = 0 ;
            string res ="" ;
            for(int j = i ; j < n ; j++){
                if(nums[j]%p == 0) cnt ++ ;
                if(cnt>k) break;
                res += nums[j] ;
                res += "." ;
                m[res]++;
            }
        }
        return m.size() ;
    }
};
