class Solution {
public:
    int numberOfSubstrings(string s) {
        int n = s.length() ;
        map<char,int> m ;
        int i = 0;
        int j = 0 ;
        int ans = 0 ;
        for(j = 0 ; j < n ; j++){
            m[s[j]]++;
            if(m.size() == 3){
                
                break;
            }
        }

        while(j<n){
            while(m.size() == 3){
                ans += 1 + (n-1-j);
                m[s[i]]--;
                if(m[s[i]] == 0) m.erase(s[i]) ;
                i++ ;
                
            }
            j++;
            m[s[j]]++ ;
        }
        return ans ;
    }
};
