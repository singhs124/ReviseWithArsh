class Solution {
public:

    char flip(char next){
        if(next == '1') return '2' ;
        return '1' ;
    }

    int magicalString(int n) {
        string s = "122";
        char next = '1' ;
        int ind = 2 ;
        int ans = 1 ;
        while(s.size() < n){
            int t = s[ind]-'0' ;
            while(t--){
                s += next ;
                ans += (s.size()<=n && next == '1')?1:0 ;
            }
            ind++;
            next = flip(next) ;
        }
        return ans ;
    }
};
