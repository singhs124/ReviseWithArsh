class Solution {
public:
    int findUnsortedSubarray(vector<int>& nums) {
        int mini = INT_MAX ;
        int maxi = INT_MIN ;
        int end = -1 , start = -1 ;
        int n = nums.size() ;
        for(int i = n-1 ; i >=0 ; i--){
            mini = min(mini , nums[i]) ;
            if(nums[i] > mini) start = i ;
        }
        for(int i = 0; i < n ;i++){
            maxi = max(maxi,nums[i]) ;
            if(nums[i] < maxi) end = i;
        }
        if(start==-1) return 0 ;
        return end-start+1 ;
    }
};
