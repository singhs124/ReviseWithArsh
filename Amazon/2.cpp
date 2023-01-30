class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& f, int src, int dst, int k) {
        
        vector<vector<pair<int,int>>> graph(n) ;
        
        for(auto it: f)
        {
            graph[it[0]].push_back({it[1] , it[2]}) ;
        }
        //dist----node---k
        priority_queue<vector<int> , vector<vector<int>> , greater<vector<int>> >pq;
        pq.push({0,src,0}) ;
        
        vector<int> stops(n , INT_MAX) ;
        
        while(!pq.empty())
        {
            auto it = pq.top() ;
            int dist = it[0] ;
            int node = it[1];
            int cstop = it[2] ;
            pq.pop() ;
            
            if(cstop > stops[node] || cstop > k+1) 
                continue ;
            
            stops[node] = cstop ;
            if(node == dst) return dist ;
            
            for(auto a : graph[node])
                pq.push({dist+a.second , a.first , cstop+1});
        }
        
        return -1 ;
    }
};
