//TLE
class Solution {
public:
    bool increasingTriplet(vector<int>& nums) {
        vector<pair<int,int>> v ;
        for(int i = 0 ; i < nums.size() ; i++){
            v.push_back({nums[i] , i}) ;
        }
        sort(v.begin() , v.end() , [](pair<int,int> a , pair<int,int> b)
        {
            return a.first < b.first ;
        });

        for(int i = 0 ; i < v.size() ; i++){
            int ind = v[i].second ;
            int val = v[i].first;
            int count = 1 ;
            if(v.size()-ind-1 < 2) continue ;
            for(int j = i+1 ; j < v.size() ; j++){
                if(v[j].second > ind && v[j].first > val){
                    ind = v[j].second ;
                    val = v[j].first ;
                    count++;
                    if(count == 3) return true ;
                }
            }
        }
        return false ;
    }
};

//O(n) & O(1)

class Solution {
public:
    bool increasingTriplet(vector<int>& nums) {
        int n = nums.size() ;
        if(n < 3) return false;
        int first = INT_MAX ;
        int second = INT_MAX ;
        for(int i = 0 ; i < n ; i++)
        {
            if(nums[i] > second) return true;
            else if(nums[i] > first && nums[i] < second) second = nums[i] ;
            else if(nums[i] < first) first = nums[i] ;
        }
        return false ;
    }
};
