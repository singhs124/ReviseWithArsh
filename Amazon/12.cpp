class Solution {
public:
    int findLength(vector<int>& nums1, vector<int>& nums2) {
        int n = nums1.size() ;
        int m = nums2.size() ;
        vector<int>next(m+1, 0) ;
        vector<int>cur(m+1 , 0) ;
        int ans = 0 ;
        for(int i = n-1 ; i >= 0 ; i--)
        {
            for(int j = m-1 ; j >= 0 ; j--)
            {
                if(nums1[i] == nums2[j]){
                    int val = 1+next[j+1] ;
                    cur[j] = val ;
                    ans = max(ans,val) ;
                }
                else 
                    cur[j] = 0 ;
            }
            next = cur ;
        }
        return ans ;
    }
};
