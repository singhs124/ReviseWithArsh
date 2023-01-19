class Solution {
public:
    string customSortString(string order, string s) {
        string ans ="" ;
        unordered_map<char,int> m ;
        for(auto it: s) m[it]++ ;
        for(int i = 0 ;i < order.size() ; i++){
            char ch = order[i] ;
            if(m.find(ch) != m.end()){
                while(m[ch]--) ans+=ch ;
                m.erase(ch) ;
            }
        }
        for(auto it: m){
            while(it.second--) ans+= it.first ;
        }
        return ans ;
    }
};

//Optimized

class Solution {
public:
    string customSortString(string order, string s) {
        string ans ="" ;
        unordered_map<char,int> m ;
        for(auto it: s) m[it]++ ;
        for(auto it: order){
            ans += string(m[it] , it) ;
            m[it] = 0 ;
        }
        for(auto it: m){
            ans += string(it.second , it.first) ;
        }
        return ans ;
    }
};
