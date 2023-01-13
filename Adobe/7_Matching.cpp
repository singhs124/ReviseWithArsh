class Solution {
public:
    int numMatchingSubseq(string s, vector<string>& words) {
        vector<vector<int>> m(26);
        int n = s.length() ;
        for(int i = 0 ; i < n ; i++){
            m[s[i]-'a'].push_back(i) ;
        }
        int ans = 0;
        for(auto word : words){
            bool found = true ;
            for(int i = 0 , prev = -1 ; found && i < word.size() ; i++){
                auto &v = m[word[i]-'a'] ;
                auto it = upper_bound(begin(v) , end(v) , prev) ;
                if(it == end(v)) found = false ;
                else prev = *it;
            }
            ans += found ;
        }
        return ans ;
    }
};
   
