// First Approach
class Solution {
public:

    bool dis(vector<int> a , vector<int> b , int check){
        int d = abs(a[0]-b[0]) + abs(a[1]-b[1]) ;
        if(d == check) return true ;
        return false ;
    }

    bool validSquare(vector<int>& p1, vector<int>& p2, vector<int>& p3, vector<int>& p4) {
        priority_queue<vector<int> , vector<vector<int>> , greater<vector<int>> > pq ;

        if(p1 == p2 || p2 == p3 || p3 == p4 || p4 == p1) return false ; 

        pq.push(p1);
        pq.push(p2);
        pq.push(p3);
        pq.push(p4) ;
        p1 = pq.top() ;
        pq.pop() ;
        p2 = pq.top() ;
        pq.pop() ;
        p4 = pq.top() ;
        pq.pop() ;
        p3 = pq.top() ;
        pq.pop() ;

        int d = abs(p1[0]-p2[0]) + abs(p1[1] - p2[1]) ;
        if(!dis(p2,p3,d) || !dis(p3,p4,d) || !dis(p4,p1,d)) return false ;
        int d1 = abs(p1[0]-p3[0]) + abs(p1[1] - p3[1]) ;
        if(!dis(p2,p4,d1)) return false ;
    

        return true  ;
    }
};




// Second Approach


class Solution {
public:

    int dis(vector<int> a , vector<int> b){
        int d = pow(a[0]-b[0] , 2) + pow(a[1]-b[1] , 2) ;
        return d ;
    }

    bool validSquare(vector<int>& p1, vector<int>& p2, vector<int>& p3, vector<int>& p4) {

        int d12 = dis(p1,p2) ;
        int d23 = dis(p2,p3) ;
        int d34 = dis(p3,p4) ;
        int d41 = dis(p4,p1) ;
        int d31 = dis(p3,p1) ;
        int d42 = dis(p4,p2) ;


        unordered_set<int> s ;
        s.insert({d12,d23,d34,d41,d42,d31}) ;

        return !s.count(0) && s.size() == 2  ;
    }
};
