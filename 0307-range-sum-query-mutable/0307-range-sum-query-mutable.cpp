class NumArray {
private:
vector<int> bit;  
    vector<int> nums;  
    int n;
    void updateBIT(int index, int delta) {
        index++; 
        while (index <= n) {
            bit[index] += delta;
            index += index & (-index);
        }
    }
    int queryBIT(int index) {
        index++;
        int sum = 0;
        while (index > 0) {
            sum += bit[index];
            index -= index & (-index);
        }
        return sum;
    }
public:
    NumArray(vector<int>& nums) {
        this->nums=nums;
        n=nums.size();
        bit.resize(n + 1, 0);
        for (int i=0;i<n; i++) {
            updateBIT(i, nums[i]);
        }
    }  
    void update(int index, int val) {
         int delta = val - nums[index];
        nums[index] = val;
        updateBIT(index, delta);
    }
    
    int sumRange(int left, int right) {
             return queryBIT(right) - queryBIT(left - 1);

    }
};

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray* obj = new NumArray(nums);
 * obj->update(index,val);
 * int param_2 = obj->sumRange(left,right);
 */