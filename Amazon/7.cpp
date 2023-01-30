class Solution {
public:
    string predictPartyVictory(string senate) {
        queue<int> rq , dq ;
        int n = senate.size() ;
        for(int i = 0 ; i < n ; i++){
            senate[i] == 'R' ? rq.push(i) : dq.push(i) ;
        }
        int a , b ;
        while(!rq.empty() && !dq.empty()){
            a = rq.front() , b = dq.front() ;
            rq.pop() , dq.pop() ;
            if(a<b) rq.push(a+n) ;
            else dq.push(b+n) ;
        }

        return rq.size()>dq.size() ? "Radiant" : "Dire" ;
    }
};
