class Solution {
public:
    int minOperations(vector<int>& nums, vector<int>& nD) {
        sort(nums.begin(), nums.end());
        sort(nD.begin(), nD.end());
        int cnt=0;
        int c=nD[0];
        for(int i=1; i<nD.size(); i++){
            c=__gcd(c, nD[i]);
        }
        if(nums[0]>c){return -1;}
        for(int i=0; i<nums.size(); i++){
            if(c%nums[i]==0){
                return cnt;
            }
            cnt++;
        }
        return -1;
    }
};
