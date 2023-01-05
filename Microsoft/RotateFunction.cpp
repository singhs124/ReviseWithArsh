class Solution {
public:
    int maxRotateFunction(vector<int>& nums) {
        int n = nums.size() ;
        int sum = 0 , mul = 0 ;
        for(int i = 0 ; i < n ; i++){
            sum += nums[i] ;
            mul += nums[i]*i ;
        }
        int i = n-1 ;
        int ans = mul ;
        while(i>=0){
            mul = mul + sum - n*nums[i] ;
            ans = max(ans,mul) ;
            i--;
        }
        return ans ;
    }
};
