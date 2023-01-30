class Solution {
public:
    int numMatchingSubseq(string s, vector<string>& words) {
        vector<vector<int>> m(26) ;

        for(int i = 0 ; i < s.length() ; i++) m[s[i]-'a'].push_back(i) ;
        int ans = 0 ;
        for(auto it: words){
            bool found = true ;
            for(int i = 0 , prev = -1 ; found && i < it.size() ; i++){
                auto &v = m[it[i]-'a'] ;
                auto it = upper_bound(begin(v) , end(v) , prev) ;
                if(it == end(v)) found = false ;
                else prev = *it ;
            }
            ans += found ;
        }
        return ans ;
    }
};
