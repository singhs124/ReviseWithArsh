class Solution {
public:
    vector<int> smallestTrimmedNumbers(vector<string>& nums, vector<vector<int>>& queries) {
        vector<int> ans ;
        int n = nums.size() ;
        int m = nums[0].size() ;
        
        
        for(auto it: queries){
            vector<pair<string,int>> pq ;

            for(int i = 0 ; i < n ; i++){
                pq.push_back({nums[i].substr(m-it[1]) , i}) ;
            }
            sort(pq.begin() , pq.end()) ;
            ans.push_back(pq[it[0]-1].second) ;
        }

        return ans ;
    }
};
