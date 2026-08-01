class Solution {
    private:
    struct cmp{
    bool operator()(pair<int,int>&a,pair<int,int>&b){
        if(a.first!=b.first)
        return a.first>b.first;  //min heap
        return a.second<b.second;  //max heap
    }
    };
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        priority_queue<pair<int,int>,vector<pair<int,int>>,cmp>pq;

        unordered_map<int,int>mp;
        for(auto i:nums)
        mp[i]++;

        for(auto i:mp){
            int elem=i.first;
            int freq=i.second;
            pair<int,int>curr={freq,elem};
            if(pq.size()<k)
            pq.push(curr);
            else{
                if(curr.first>pq.top().first){
                    pq.pop();
                    pq.push(curr);
                }
            }
        }
        vector<int>res;
        while(!pq.empty()){
            res.push_back(pq.top().second);
            pq.pop();
        }
        return res;

        
    }
};