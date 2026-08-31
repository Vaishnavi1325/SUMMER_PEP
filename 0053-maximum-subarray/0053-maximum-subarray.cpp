class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int curr=0;
        int maxfinal=INT_MIN;
        for(int i:nums){
            curr=max(curr+i,i);
            maxfinal=max(curr,maxfinal);
        }
        return maxfinal;
    }
};