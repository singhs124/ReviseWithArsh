class Solution {
public:
    int mod = 1e9+7 ;
    int countNicePairs(vector<int>& nums) {
        
        int n = nums.size() ;
        vector<int> nums2(n) ;
        for(int i = 0 ; i < n; i++){
            int rev = 0;
            int num = nums[i] ;
            while(num){
                rev = rev*10 + num%10 ;
                num= num/10 ;
            }
            nums2[i] = nums[i] - rev ;   
        }
        unordered_map<int,long> m ;
        long  ans = 0 ;
        for(auto it: nums2){
            m[it]++;
        }
        for(auto it: m){
            ans = (ans + (it.second*(it.second-1))/2) % mod ;
        }
        return ans ;
    }
};

