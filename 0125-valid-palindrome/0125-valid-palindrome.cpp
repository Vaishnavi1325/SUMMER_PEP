class Solution {
private:
    bool isValid(char ch){
        if((ch>='a'&& ch <='z') || (ch>='A'&& ch<='Z') || (ch>='0'&& ch<='9'))
        return 1;
        return 0;
    }
public:
    bool isPalindrome(string s) {
        int n =s.size();
        string temp="";
        for(int i=0;i<n;i++){
            if(isValid(s[i])) temp.push_back(s[i]);
        }
        for(int i=0;i<temp.size();i++){
            temp[i]=tolower(temp[i]);
        }

        int i=0;
        int j=temp.size()-1;
        while(i<j){
            if(temp[i]!=temp[j]) return false;
            i++;
            j--;
        }
        return true;
    }
};
