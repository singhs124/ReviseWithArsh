class Solution {
public:

    bool cycle_dfs(int node, vector<int> &vis, vector<int> &dfsvis, vector<int> adj[]){
        vis[node] = 1;
        dfsvis[node] = 1;
        for(auto it: adj[node]){
            if(!vis[it]){
                if(cycle_dfs(it, vis, dfsvis, adj))
                    return true;
            }
            else if(dfsvis[it])
                return true;
        }
        dfsvis[node] = 0;
        return false;
    }
    
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        vector<int> vis(numCourses, 0);
        vector<int> dfsvis(numCourses, 0);
        int edges = prerequisites.size();
        vector<int>adj[numCourses];// adj list
        
        for(int i = 0;i<edges;i++){
            int u = prerequisites[i][0];
            int v = prerequisites[i][1];
            adj[v].push_back(u);
        }
        
        for(int i=0; i<numCourses; i++){
            if(!vis[i])
                if(cycle_dfs(i, vis, dfsvis, adj))
                    return false;
        }
        return true;
    }
};

