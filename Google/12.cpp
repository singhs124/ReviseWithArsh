class Solution {
public:

    bool ok(string s){
        if(s.length() > 3 || s.length() == 0 || (s[0]=='0' && s.length()>1) || stoi(s) > 255) return false;
        return true ;
    }

    vector<string> restoreIpAddresses(string s) {
        vector<string> ans ;
        int n = s.length() ;
        for(int i = 1 ; i < 4 && i < n ; i++){
            for(int j = i+1 ; j < i+4 && j<n ; j++){
                for(int k = j+1 ; k < j+4 && k<n ; k++){
                    string s1 = s.substr(0,i),
                    s2 = s.substr(i,j-i) ,
                    s3 = s.substr(j,k-j),
                    s4 = s.substr(k) ;

                    if(ok(s1) && ok(s2) && ok(s3) && ok(s4)){
                        string temp = s1+"."+s2+"."+s3+"."+s4 ;
                        ans.push_back(temp) ;
                    }
                }
            }
        }
        return ans ;
    }
};
