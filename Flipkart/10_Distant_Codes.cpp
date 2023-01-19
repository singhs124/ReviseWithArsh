class Solution {
public:
    vector<int> rearrangeBarcodes(vector<int>& b) {
        unordered_map<int,int> m ;
        set<pair<int,int>> s ;
        for(auto it: b) m[it]++ ;
        for(auto it: m) s.insert({it.second,it.first}) ;
        int pos = 0 ;
        for(auto it = s.rbegin() ; it != s.rend() ; it++){
            for(int cnt = 0 ; cnt<it->first ; cnt++ , pos += 2){
                if(pos>=b.size()) pos = 1 ;
                b[pos] = it->second ;
            }
        }
        return b ;

    }
};
