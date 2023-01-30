class video{
    public:
    long sum = 0 ; // sum of views
    string small ; //smallest id
    int max_views = 0 ; // max view ;
};

class Solution {
public:
    vector<vector<string>> mostPopularCreator(vector<string>& c, vector<string>& ids, vector<int>& v) {
        unordered_map<string,video> m ;
        long count = 0;
        for(int i = 0 ; i < c.size() ; i++){
            if(!m.count(c[i])){
                m[c[i]] = {
                    v[i] ,ids[i] ,v[i] 
                };
                count = max(count , m[c[i]].sum) ;
                continue ;
            }
            m[c[i]].sum += v[i] ;

            if(m[c[i]].max_views < v[i] || (m[c[i]].max_views == v[i]  && m[c[i]].small > ids[i])){
                m[c[i]].max_views = v[i] ;
                m[c[i]].small = ids[i] ;
            }
            count = max(count , m[c[i]].sum) ;

        }
        vector<vector<string>> ans;

        for(auto it: m){
            if(it.second.sum == count){
                ans.push_back({it.first , it.second.small}) ;
            }
        }
        return ans ;

        
    }
}; 
