class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        vector<int> dis(n+1,1e9+7) ;
        vector<pair<int,int>> adj[n+1] ;
        for(auto it: times){
            int u = it[0] , v = it[1] , w = it[2] ;
            adj[u].push_back({v,w}) ;
        }
        priority_queue<pair<int,int> , vector<pair<int,int>> , greater<pair<int,int>>> pq;
        dis[k] = 0 ;
        pq.push({k,0}) ;
        while(!pq.empty()){
            auto it = pq.top() ;
            pq.pop() ;
            int node = it.first , d = it.second ;
            for(auto it: adj[node]){
                int child = it.first , child_d = it.second ;

                if(dis[child] > d+child_d){
                    dis[child] = d+child_d ;
                    pq.push({child,d+child_d}) ;
                }
            }
        }
        int res = 0 ;
        for(int i = 1 ; i <= n ; i++){
            if(dis[i] == 1e9+7) return -1 ;
            res = max(res,dis[i]) ;
        }
        return res ;
        
    }
}; 
