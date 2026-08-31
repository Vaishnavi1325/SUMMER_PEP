class Solution {
public:
    double findMaxAverage(vector<int>& nums, int k) {
       int left =0,right=0;
       double average;
        double maxav = -DBL_MAX;
        int sum=0;
        while(right<nums.size()){
            sum+=nums[right];
            if(right-left+1>=k){
            average=(double)sum/k;
            maxav=max(maxav,average);
            sum-=nums[left];
            left++;
        }
        right++;
       } 
       return maxav;
    }
};