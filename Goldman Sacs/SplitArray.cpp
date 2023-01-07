// Wrong Answer
class Solution {
public:
    bool isPossible(vector<int>& nums) {
        unordered_set<int> s ;

        for(auto it:nums) s.insert(it) ;

        for(auto it: s){
            if(s.count(it+1) && s.count(it+2)) return true ;
        }
        return false ;
    }
};

//Remember i have to split the whole array not just find the subsequence

class Solution {
public:
    bool isPossible(vector<int>& nums) {
        unordered_map<int,int> m1 ; // checking unchecked numbers
        unordered_map<int,int> m2 ; // checking last element of sequence ;

        for(auto it: nums) m1[it]++ ;
        for(auto it: nums)
        {
            if(m1[it] == 0) continue ;
            if(m2[it-1] > 0){
                m2[it-1]--;
                m2[it]++;
                m1[it]--;
            }
            else{
                if(m1[it+1] == 0 || m1[it+2] == 0) return false ;
                m1[it]--;
                m1[it+1]--;
                m1[it+2]-- ;
                m2[it+2]++;
            }
        }
        return true ;
    }
};
