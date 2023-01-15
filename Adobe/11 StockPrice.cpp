class StockPrice {
public:
    map<int,int , greater<int>> m ;
    multiset<int> s ;
    
    void update(int t, int p) {
        if(m.find(t) != m.end()){
            s.erase(s.find(m[t])) ;
        }
        m[t] = p ;
        s.insert(p) ;
    }
    
    int current() {
        auto it = m.begin() ;
        return it->second ;
    }
    
    int maximum() {
       auto it = --s.end() ;
       return *it; 
    }
    
    int minimum() {
        return *s.begin() ;
    }
};
