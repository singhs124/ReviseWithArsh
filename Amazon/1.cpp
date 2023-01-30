class Solution {
public:
vector<int> nums ;
    Solution(vector<int>& nums) {
        this->nums = nums ;
    }
    
    vector<int> reset() {
        return nums ;
    }
    
    vector<int> shuffle() {
        vector<int> arr(nums) ;
        int n = nums.size() ;
        for(int i = 0 ; i < n ; i++){
            int pos = rand()%(n-i) ;
            swap(arr[i+pos] , arr[i]) ;
        }
        return arr ;
    }
};
