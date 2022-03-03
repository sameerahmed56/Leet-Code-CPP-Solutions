class Solution {
public:
    int myAtoi(string s) {
        int n = s.size();
        long int ans = 0;
        bool foundDigit = false, isNegative = false;
        for(char c: s){
            if(c==' '){
               if(foundDigit){
                   return isNegative ? (int)-ans : (int)ans;
               } 
            }
            else if(c == '-'){
                if(foundDigit){
                    return isNegative ? (int)-ans : (int)ans;
                }
                isNegative = true;
                foundDigit = true;
            }
            else if(c == '+'){
                if(foundDigit){
                    return isNegative ? (int)-ans : (int)ans;
                }
                isNegative = false;
                foundDigit = true;
            }
            else if(isdigit(c)){
                foundDigit = true;
                ans = ans*10 + (c-'0');
                if(ans > 2147483647 && !isNegative){
                    return 2147483647;
                }
                if(ans > 2147483648 && isNegative){
                    return -2147483648;
                }
            }
            else{
                return isNegative ? (int)-ans : (int)ans;
            }
        }
        return isNegative ? (int)-ans : (int)ans;
    }
};