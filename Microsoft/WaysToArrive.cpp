class comp{
    public:
    bool operator()(pair<long long,long long> a , pair<long long,long long> b){
        return a.first > b.first ;
    }
};

class Solution {
public:
    int countPaths(int n, vector<vector<int>>& roads) {
        vector<vector<pair<long long,long long>>> adj(n+1) ;
        for(auto it: roads){
            adj[it[0]].push_back({it[1] , it[2]}) ;
            adj[it[1]].push_back({it[0] , it[2]}) ;
        }
        long long MOD = 1e9+7 ;
        vector<long long> dis(n+1 , 1e15) ;
        vector<long long> dp(n+1, 0) ;

        
        priority_queue<pair<long long,long long> , vector<pair<long long,long long>> , comp> q ;

        q.push({0,0}) ;
        dis[0] = 0 ;
        dp[0] = 1;

        while(!q.empty()){
            long long node = q.top().second ;
            long long wt = q.top().first ;
            q.pop();
            //if(dis[node] < wt) continue ;

            for(auto it: adj[node]){
                long long child = it.first ;
                long long childwt = it.second ;

                if(wt+childwt == dis[child]){
                    dp[child] = (dp[child] + dp[node])%MOD ;
                }

                if(wt+childwt < dis[child]){
                    dp[child] = dp[node]%MOD ;
                    dis[child] = wt+childwt ;
                    q.push({dis[child] , child});
                }
                
            }
        }
        return dp[n-1] ;
    }
};
