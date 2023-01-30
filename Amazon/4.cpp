class TweetCounts {
public:
map<string,multiset<int>> m ;
    
    
    void recordTweet(string tweetName, int time) {
        m[tweetName].insert(time) ;
    }
    
    vector<int> getTweetCountsPerFrequency(string freq, string tweetName, int startTime, int endTime) {
        
        int inc = 0 ;
        if(freq == "minute") inc = 60;
        else if(freq == "hour") inc = 3600 ;
        else inc = 86399 ;
        vector<int> ans((endTime-startTime)/inc + 1) ;
        auto it = m.find(tweetName) ;
        if(it != m.end()){
            for(auto s = it->second.lower_bound(startTime) ; s != it->second.end() && *s <= endTime ; ++s){
                ++ans[(*s-startTime)/inc] ;
            }
        }
        return ans ;
    }
};
