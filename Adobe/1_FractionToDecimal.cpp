class Solution {
public:
    string fractionToDecimal(int numu, int denu) {
        
        string ans ="" ;
        if(!numu) return "0" ;
        if((numu < 0 && denu < 0) || (numu > 0 && denu >0)) ans="";
        else ans += '-';
        long num = abs(numu) ;
        long den = abs(denu) ;
        ans += to_string(num/den) ;
        long rem = num % den ;
        if(!rem) return ans ;
        ans+='.' ;
        unordered_map<long,int> m ;

        while(rem){
            if(m.find(rem) != m.end()){
                ans.insert(m[rem] , "(") ;
                ans += ')' ;
                break;
            }

            m[rem] = ans.size() ;
            rem = rem*10 ;
            ans += to_string(rem/den) ;
            rem = rem % den ;
        }
        return ans ;
    }
};
