class Solution {
public:
    bool hasAllCodes(string s, int k) {
        set<string> st ;
        int sz = pow(2,k) ;
        int i = 0 , j = k-1 ;
        string dummy = s.substr(i,j+1) ;
        st.insert(dummy) ;
        i++,j++;
        while(j<s.length()){
            dummy.erase(0,1) ;
            dummy += s[j] ;
            st.insert(dummy) ;
            i++,j++;
            if(st.size() == sz) return true ;
        }
        return st.size()==sz ;
    }
};
