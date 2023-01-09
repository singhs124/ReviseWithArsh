#include<bits/stdc++.h>
class transaction{
    public:
    int time ;
    int amount ;
    string city ;
    string tran;
    bool marked ;

    transaction(int t , int a , string c , string full){
        time = t ;
        amount = a ;
        city = c ;
        tran = full ;
        marked = false ;
    }
};


class Solution {
public:
    vector<string> invalidTransactions(vector<string>& arr) {
        unordered_map<string , vector<transaction*>> m ;
        for(auto trans: arr){
            istringstream ss(trans) ;
            string token = "";
            getline(ss , token, ',');
            string name = token ;
            getline(ss , token, ',');
            int time = stoi(token) ;
            getline(ss , token, ',');
            int amount = stoi(token) ;
            getline(ss , token, ',');
            string city = token ;

            transaction *t = new transaction(time,amount,city,trans);
            m[name].push_back(t) ;
        }

        vector<string> res ;

        for(auto it: m){
            sort(it.second.begin() , it.second.end() , [](const transaction* a , const transaction* b){
                return a->time < b->time ;
            });


            for(int i = 0 ; i < it.second.size() ; i++){
                if(it.second[i]->amount > 1000)
                {
                    res.push_back(it.second[i]->tran) ;
                    it.second[i]->marked = true ;
                }

                if(i>0 && it.second[i]->time <= it.second[i-1]->time + 60)
                {
                    int r = i-1 ;
                    while(r>=0 && it.second[r]->time >= it.second[i]->time - 60)
                    {
                        if(it.second[i]->city != it.second[r]->city){
                            if(!it.second[r]->marked){
                                res.push_back(it.second[r]->tran) ;
                                it.second[r]->marked = true ;
                            }
                            if(!it.second[i]->marked){
                                res.push_back(it.second[i]->tran) ;
                                it.second[i]->marked = true ;
                            }
                        }
                        r-- ;
                        
                    }
                   
                }
            }
        }
        return res ;


    }
};
