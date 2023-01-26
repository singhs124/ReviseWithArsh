class Solution {
public:
    int distinctEchoSubstrings(string t) {
        set<string> st ;
        int n = t.size() ;
        for(int len = 1 ; len <= n/2 ; len++){
            int count = 0 ;
            for(int l=0 , r=len ; r < n ; l++,r++)
            {
                if(t[l] == t[r]) count++ ;
                else count = 0 ;

                if(count == len){
                    st.insert(t.substr(l,len)) ;
                    count-- ;
                }
            }
        }
        return st.size() ;
    }
};
