class Solution {
public:
    string getHint(string s, string g) {
        map<char , set<int>> m ;
        string ans = "" ;
        int cow = 0 ;
        int bull = 0 ;
        for(int i = 0 ; i < s.length() ; i++)
        {
            m[s[i]].insert(i) ;
        }
        
        for(int i = 0 ; i < g.length() ; i++){
            if(m.find(g[i]) != m.end()){
                cow++ ;
                if(m[g[i]].count(i)){
                    cow-- ;
                    bull++;
                    m[g[i]].erase(i) ;
                }
                else{
                    m[g[i]].erase(i) ;
                }
                if(m[g[i]].empty()) m.erase(g[i]) ;
            }
        }
        ans = to_string(bull) + "A" + to_string(cow) + "B" ;
        return ans ;
    }
};
