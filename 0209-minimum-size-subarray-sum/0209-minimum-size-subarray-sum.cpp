class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {

        int left=0,right=0,sum=0,ans=INT_MAX;
        while(right<nums.size()){
                sum+=nums[right];
                right++;
                while(sum>=target){
                    ans=min(ans,right-left);
                    sum-=nums[left];
                    left++;
                }
        }

        return ans==INT_MAX?0:ans;
    }
};