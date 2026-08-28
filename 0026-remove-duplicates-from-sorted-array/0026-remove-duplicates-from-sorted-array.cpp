class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        // int i = 0;
        // int j = 1;
        // while(j<nums.size()){
        //     if(nums[i]==nums[j]){
        //         j++;
        //     }else{
        //         i+=1;
        //         nums[i]=nums[j];
        //     }
        // }
        // return i+1;
        int slow=0;
        int fast=1;
        while(fast<nums.size()){
            if(nums[slow]!=nums[fast]){
                slow++;
                nums[slow]=nums[fast];
                fast++;
            }
            else{
                fast++;
            } 
        }
        return slow+1;
    }
};