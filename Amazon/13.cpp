#define psi pair<int, string>

class myComp{
    public:
        bool operator()(const psi &p1 , const psi &p2)
        {
            if(p1.first == p2.first) return p1.second < p2.second ;
            return p1.first > p2.first ;
        }
};

class Solution {
public:

    vector<string> topKFrequent(vector<string>& words, int k) {
        int maxi = 0 ;
        unordered_map<string , int> s ;
        for(auto it: words)
            s[it]++ ;

        priority_queue<psi , vector<psi> , myComp> pq;

        for(auto it: s)
        {
            pq.push({it.second , it.first}) ;
            if(pq.size() > k) pq.pop() ;
        }

        vector<string>ans(k) ;
        int m = k-1 ;

        while(!pq.empty())
        {
            ans[m--] = pq.top().second ;
            pq.pop() ;
        }
        
        return ans ;
    }
};
