//Time Limit Exceeded
class Solution {
public:
    int trailingZeroes(int n) {
        
        vector<int> ans ;
        int count = 0  ;
        
        ans.push_back(1) ;
        for(int num = 2 ; num <= n ; num++){
            int carry = 0 ;
            for(int i = 0 ; i < ans.size() ; i++){
                int val = ans[i]*num + carry ;
                ans[i] = val%10 ;
                carry = val/10 ;
            }
            while(carry){
                ans.push_back(carry%10) ;
                carry = carry/10 ;
            }
        }
        
        for(int i = 0; i < ans.size() ; i++){
            if(ans[i] == 0){
                count++ ;
            }
            else break;
        }
        return count ;
    }
};

//Correct Solution


class Solution {
public:
    int trailingZeroes(int n) {
        int ans =0;
        while(n>=5){
            ans += n/5 ;
            n = n/5 ;
        }
        return ans ;
    }
};

