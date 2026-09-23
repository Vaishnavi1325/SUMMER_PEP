class Solution {
public:
    bool check(vector<int>& nums) {
        int n=nums.size();
        int d=0;
        for (int i = 0; i < n; i++) {
            if (nums[i] > nums[(i+1) % n]) {
                d++;
            }
        }
        return d<=1;
    }
};