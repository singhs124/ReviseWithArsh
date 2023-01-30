class Solution {
public:
unordered_set<string> sus ;
int res ;
int n ;
string st ;
    int maxUniqueSplit(string s) {
        n = s.length() ;
        res = 0;
        st = s;
        check(0) ;
        return res ;

    }

    void check(int p){
        if(p == n){
            int r = sus.size() ;
            res = max(res,r) ;
            return ;
        }
        string d = "";
        for(int i = p ; i < n ; i++){
            d += st[i] ;
            if(sus.find(d) == sus.end()){
                sus.insert(d) ;
                check(i+1);
                sus.erase(d) ;
            }
        }
    }
};
