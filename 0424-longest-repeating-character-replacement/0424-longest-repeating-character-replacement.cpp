class Solution {
public:
    int characterReplacement(string s, int k) {
        unordered_map<char,int>mp;
        int left=0,right=0,ans=0,maxFreq=0;
        while(right<s.size()){
            mp[s[right]]++;
            maxFreq = max(maxFreq, mp[s[right]]);
            while((right-left+1)-maxFreq>k){
                mp[s[left]]--;
                left++;
            }
            ans=max(ans,right-left+1);
            right++;
        }
        return ans;
    }
};