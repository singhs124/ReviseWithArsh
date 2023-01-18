class Solution {
public:
    vector<pair<int,int>>ans ; //node---cnt
    
    static bool cmp(pair<int,int> a, pair<int,int> b)
    {
        if(a.second != b.second) return a.second<b.second ;
        return a.first > b.first ;
    }
    void fun(int i , int n , vector<pair<int,int>> adj[] , int r) 
    {
        priority_queue<pair<int,int> , vector<pair<int,int>> , greater<pair<int,int>>> pq ;  //node---distance
        vector<int> dis(n+1 , 1e9+7) ;
        int src = i ;
        dis[src] = 0;
        
        pq.push({src,0}) ;
        
        while(!pq.empty())
        {
            int node = pq.top().first ;
            int distance = pq.top().second ;
            pq.pop() ;
            
            for(auto it: adj[node])
            {
                int next = it.first ;
                int w = it.second ;
                
                if(dis[next] > dis[node] + w)
                {
                    dis[next] = dis[node]+w;
                    pq.push({next,dis[next]}) ;
                }
            }
        }
        int cnt = 0 ;
        for(int i = 0 ; i < n ; i++)
        {
            if(i!=src && dis[i] <= r)
            {
                cnt++ ;
            }
        }
        ans.push_back({src,cnt}) ;
    }
    int findTheCity(int n, vector<vector<int>>& edges, int distanceThreshold) {
        
        vector<pair<int,int>> adj[n+1] ;
        for(int i = 0 ; i < edges.size() ; i++)
        {
            adj[edges[i][0]].push_back({edges[i][1] , edges[i][2]}) ;
            adj[edges[i][1]].push_back({edges[i][0] , edges[i][2]}) ;
        }
        
        for(int i = 0 ; i < n ; i++)
            fun(i,n,adj,distanceThreshold);
        
        sort(ans.begin() , ans.end() , cmp) ;
        
        return ans[0].first ;
    }
};
