class Solution {
public:
    int trap(vector<int>& height) {
        int left = 0;
        int right = height.size()-1;
        int leftmax=0,rightmax=0;
        int water=0;
        while(left<right){
            if(height[left]<=height[right])
            {
                //process left 
                if(height[left]<leftmax){
                    water+=leftmax-height[left];
                }
                else {
                    leftmax=height[left];
                }
                left++;
            }
            else {
                //right process
                if (height[right] >= rightmax) {
                rightmax = height[right];
            }
            else {
                water += rightmax - height[right];
            }

            right--;
        }

        }
        return water;
    }
};