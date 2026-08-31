class Solution {
public:
    int thirdMax(vector<int>& nums) {
           long long fmax = LLONG_MIN;
        long long smax = LLONG_MIN;
        long long tmax = LLONG_MIN;
        for(int i:nums){
             if (i == fmax || i == smax || i == tmax)
                continue;
            if(i>fmax){
                tmax=smax;
                smax=fmax;
                fmax=i;
            }
            else if(i>smax && fmax>i){
                tmax=smax;
                smax=i;
            }
             else if (i > tmax) {
                tmax = i;
            }

        }
          if (tmax == LLONG_MIN)
            return fmax;
        return tmax;
    }
};