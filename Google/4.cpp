class Solution {
public:
    int totalFruit(vector<int>& a) {
        int n = a.size() ;
        unordered_map<int,int> m ;
        int i = 0 , j = 0 ;
        while(j<n){
            m[a[j]]++;
            if(m.size() > 2){
                if(--m[a[i]] == 0) m.erase(a[i]) ;
                i++ ;
            }
            j++;
        }
        return j-i ;
    }
};
