class Solution {
public:
    vector<int> par , dis;
    void dfs(int node ,int p , int d, vector<int> adj[]){
        par[node] = p ;
        dis[node] = d ;
        for(auto it: adj[node]){
            if(it == par[node]) continue ;
            dfs(it,node,d+1,adj);
        }
    }

    int dfs2(int node, vector<int>& amt,  vector<int> adj[]){
        int a = amt[node] ;
        int ans = -1e9+7 ;
        for(auto it: adj[node])
        {
            if(it == par[node]) continue ;
            ans = max(ans, dfs2(it,amt,adj)) ;
        }
        if(ans == -1e9+7) return a ;
        return a+ans ;
    }

    int mostProfitablePath(vector<vector<int>>& edges, int bob, vector<int>& amt) {
        
        int n = amt.size() ;
        vector<int> adj[n] ;
        par.resize(n) ;
        dis.resize(n) ;
        for(auto it: edges){
            adj[it[0]].push_back(it[1]) ;
            adj[it[1]].push_back(it[0]) ;
        }

        par[0] = 0 ;
        dis[0] = 0 ;

        dfs(0,0,0,adj) ;


        int curr = bob ;
        int bob_dis = 0 ;

        while(curr != 0){
            if(dis[curr] > bob_dis) amt[curr] = 0 ;
            else if(dis[curr] == bob_dis) amt[curr] = amt[curr]/2 ;
            curr = par[curr];
            bob_dis++;
        }

        return dfs2(0,amt,adj) ;
    }
};
