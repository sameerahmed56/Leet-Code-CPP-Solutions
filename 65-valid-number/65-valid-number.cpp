class Solution {
public:
    bool isNumber(string s) {
        bool sign = 0, decimal = 0, digit = 0, expo = 0;
        int n=s.size();
        if(n==0) return false;
        for(char c: s){ 
            if(c == '+' || c == '-'){
                if(digit || sign || decimal) return false;
                sign = 1;
            }
            else if(c >= '0' && c<= '9'){
                digit = 1;
            }
            else if(c == '.'){
                if(decimal || expo) return false;
                decimal = 1;
            }
            else if(c == 'e' || c == 'E'){
                if(!digit || expo) return false;
                sign = 0;
                digit = 0;
                decimal = 0;
                expo = 1;
            }
            else return false;
        }
        return digit;
    }
};