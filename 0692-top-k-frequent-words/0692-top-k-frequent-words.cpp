class Solution {
    struct cmp{
      bool operator()(pair<int,string>&a,pair<int,string>&b){
        if(a.first!=b.first)
        return a.first>b.first;  //min heap
        return a.second<b.second;  //max heap
      }
    };
public:
    vector<string> topKFrequent(vector<string>& words, int k) {
        priority_queue<pair<int,string>,vector<pair<int,string>>,cmp>pq;
        unordered_map<string,int>mp;
        for(auto i:words)
        mp[i]++;

        for(auto i:mp){
            string s=i.first;
            int freq=i.second;
            pair<int,string>curr={freq,s};
            if(pq.size()<k)
            pq.push(curr);
            else{
                if(pq.top().first<curr.first || (pq.top().first == curr.first && pq.top().second > curr.second) ){
                    pq.pop();
                    pq.push(curr);
                }
            }
        }
        vector<string>res;
        while(!pq.empty()){
            res.push_back(pq.top().second);
            pq.pop();
        }
        reverse(res.begin(), res.end());
        return res;
    }
};