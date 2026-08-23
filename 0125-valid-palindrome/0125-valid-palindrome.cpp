class Solution {
private:
bool isValid(char &ch){
     if((ch>='a'&& ch <='z') || (ch>='A'&& ch<='Z') || (ch>='0'&& ch<='9'))
        return 1;
        return 0;
}
public:
    bool isPalindrome(string s) {
        string sr="";
        for(int i=0;i<s.size();i++){
            if(isValid(s[i])) {
                s[i]=(char)tolower(s[i]);
                sr.push_back(s[i]);
            }
        }
        int l=0;
        int r=sr.size()-1;
        while(l<r){
            if(sr[l]!=sr[r]) return false;
            l++;
            r--;
        }
        return true;

    }
};