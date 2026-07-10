class Solution {
    private:
    struct comp{
        bool operator()(pair<int,int>a,pair<int,int>b){
            if(a.first!=b.first)
            return a.first>b.first;  //min heap
            return a.second>b.second;  //min heap
        }
    };
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        int n=nums.size();
        //create a pair heap
        priority_queue<pair<int,int>,vector<pair<int,int>>,comp>pq;
        //hashmap 
        unordered_map<int,int>mp;
        for(auto i:nums)
        mp[i]++;
        for(auto i:mp){
            int ele=i.first;
            int freq=i.second;
            pair<int,int>curr={freq,ele};
            if(pq.size()<k){
                pq.push(curr);
                continue;
            }
            if(curr.first<pq.top().first) continue;
            pq.pop();
            pq.push(curr);
        }
        vector<int>res;
        while( !pq.empty()){     //pq heap contains only top k elements(O(nlogk))
            res.push_back(pq.top().second);
            pq.pop();
        }
        return res;




    }
};