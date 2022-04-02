class Solution {
public:
    bool isPalindrome(string s) {
        int n = s.size();
        int l = 0, r = n - 1;
        while(l <= r){
            if(s[l++] != s[r--])
                return false;
        }
        return true;
    }
public:
    bool validPalindrome(string s) {
        for (int l = 0, r = s.size() - 1; l < r; l++, r--){
             if(s[l] != s[r])
                 return isPalindrome(s.substr( l + 1, r - l )) || isPalindrome(s.substr(l, r  - l));
                 
        }
        return true;
    }
};