class Solution {
private:
bool check(unordered_map<char,int>& mp,
            unordered_map<char,int>& mp2) {

        for(auto x : mp) {
            if(mp2[x.first] < x.second)
                return false;
        }

        return true;
    }
public:
    string minWindow(string s, string t) {
        int i=0,j=0;
        int minLen=INT_MAX,start=0;
        unordered_map<char,int>mp;
        unordered_map<char,int>mp2;
        for(char ch:t)
        mp[ch]++;
        while(j<s.size()){
            mp2[s[j]]++;
            j++;
            while(check(mp,mp2)){ //check if window is valid 
                //If I don't have an answer yet OR the current valid window is smaller than my previous answer, save the current window
                if(j-i<minLen){
                    minLen=j-i;
                    start=i;
                } 
                mp2[s[i]]--;
                i++;
                //shrink from left
            }

        }
        if(minLen==INT_MAX) return "";
        return s.substr(start,minLen);

    }
};