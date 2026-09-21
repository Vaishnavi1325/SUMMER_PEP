class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        unordered_map<char,int>mp1;
        unordered_map<char,int>mp2;
        int left=0,right=0;
        int size=s1.size();
        for(char ch:s1)
        mp1[ch]++;

        while(right<s2.size()){
            mp2[s2[right]]++;
            right++;
            if(right-left==size){
                if(mp2==mp1) return true;
                else{
                    mp2[s2[left]]--;  
                    if (mp2[s2[left]] == 0)
                    mp2.erase(s2[left]);//remove if freq=1
                    left++;
                 
                }
            }

        }
        return false;

    }
};