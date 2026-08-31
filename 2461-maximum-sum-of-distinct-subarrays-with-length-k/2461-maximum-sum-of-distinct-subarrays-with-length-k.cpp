class Solution {
public:
    long long maximumSubarraySum(vector<int>& nums, int k) {
        int left = 0, right = 0;
        long long sum=0,maxsum=0;
        unordered_map<int,int>freq;
        while(right<nums.size())
        {
            //elements should not be repeated
             while (freq[nums[right]] > 0) {
                freq[nums[left]]--;
                sum -= nums[left];
                left++;
            }

            // Add new element
            freq[nums[right]]++;
            sum += nums[right];
            
            if(right-left+1==k ){
                maxsum=max(sum,maxsum);
                freq[nums[left]]--;
                sum-=nums[left];
                left++;
            }
            right++;
        }
        return maxsum;

    }
};