

class Solution {
public:
    bool static comp(pair<int,int> a , pair<int,int> b){
    return (a.second < b.second) ; 
    }

    int findMaximizedCapital(int k, int w, vector<int>& p, vector<int>& c) {
        vector<pair<int,int>> v ;
        int n = p.size() ;
        for(int i = 0 ; i < n ; i++){
            v.push_back({p[i] , c[i]}) ;
        }
        sort(v.begin() , v.end() , comp) ;
        priority_queue<int> pq ;
        int i = 0 ;
        
        while(k--){
            while(i<n && w >= v[i].second ){
                pq.push(v[i].first) ;
                i++ ;
            }
        
            if(!pq.empty()){
                w += pq.top() ;
                pq.pop() ;
            }
        }
        return w ;
    }
};
