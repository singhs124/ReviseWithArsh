class Solution {
public:
    //i ----> student , j ----> mentor 
    int cal(int i , int j , vector<vector<int>>& students, vector<vector<int>>& mentors){
        int m = students[0].size() ;
        int sum = 0 ;
        for(int k = 0 ; k < m ; k++){
            if(students[i][k] == mentors[j][k]) sum++ ;
        }
        return sum ;
    }

    int fun(int i , int n , vector<vector<int>>& students, vector<vector<int>>& mentors , vector<bool> &vis){
        if(i==n) return 0 ;
        int ans = 0 ;
        for(int j = 0 ; j < n ; j++){
            if(!vis[j]){
                vis[j] = 1 ;
                ans = max(ans , cal(i,j,students,mentors) + fun(i+1,n,students,mentors,vis)) ;
                vis[j] = 0 ;
            }
        }
        return ans ;
    }

    int maxCompatibilitySum(vector<vector<int>>& students, vector<vector<int>>& mentors) {
        int n = students.size() ;
        vector<bool> vis(n+1,0) ;
        return fun(0,n,students,mentors,vis) ;
    }
};
