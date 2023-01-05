class Solution {
public:
    int findUnsortedSubarray(vector<int>& nums) {
        int n = nums.size() ;
        

        int curr_min = 1e9+7 ;
        int curr_max = -1e9+7 ;
        int start = -1 ;
        int end = -1 ;
        for(int i = n-1 ; i >= 0 ; i--){
            if(curr_min > nums[i]) curr_min = nums[i] ;
            if(nums[i] > curr_min) start = i ;
        }

        for(int i = 0 ; i < n ; i++){
            if(curr_max < nums[i]) curr_max = nums[i] ;
            if(nums[i] < curr_max) end = i ;
        }

        if(start== -1) return 0;
        return end-start+1 ;
        

    }
};
