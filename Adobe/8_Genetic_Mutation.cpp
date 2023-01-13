class Solution {
public:
    int minMutation(string start, string end, vector<string>& b) {
        queue<string> q ;
        unordered_map<string,bool> vis ;
        q.push(start) ;
        vis[start] = true ;
        int steps = 0 ;
        while(!q.empty()){
            int n = q.size() ;
            for(int i = 0 ; i < n ; i++){
                string s = q.front() ;
                q.pop();
                if(s == end) return steps;
                for(int j = 0 ; j < 8 ; j++){
                    char temp = s[j] ;
                    for(auto it: "ACGT"){
                        s[j] = it;
                        if(!vis[s] && find(begin(b) , end(b) , s) != b.end()){
                            q.push(s);
                            vis[s] = true;
                        }
                    }
                    s[j] = temp;

                }
            }
            steps++;
        }
        return -1;
    }
};
