class Solution {
private:
struct cmp{
    bool operator()(pair<int,char>p1,pair<int,char>p2){
        if(p1.first!=p2.first) return p1.first<p2.first;  //max heap
        return p1.second<p2.second;     //max heap
    }

};
public:
    string reorganizeString(string s) {
        string res="";
        int seat=0;
        unordered_map<char,int>mp;
        priority_queue<pair<int, char>,vector<pair<int,char>>,cmp>pq;
        for(auto i:s){
            mp[i]++;
        }
        for(auto i:mp){
            char ele=i.first;
            int freq=i.second;
            pair<int,char>curr={freq,ele};
            pq.push(curr);
        }
        while(!pq.empty()){
            pair<int,char>a=pq.top();
            pq.pop();
            if(seat==0 || res[seat-1]!=a.second)
            {
                res.push_back(a.second);
                seat++;
                a.first--;
                if(a.first>0)
                pq.push(a);
            }
            else {
                if(pq.empty()) return "";
                pair<int,char>b=pq.top();
                pq.pop();
                res.push_back(b.second);
                seat++;
                b.first--;
                if(b.first>0) pq.push(b);
                pq.push(a);
            }


        }
        return res;
    }
};