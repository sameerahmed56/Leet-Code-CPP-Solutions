class Solution {
public:
    int minAddToMakeValid(string S) {
        int open = 0, close = 0;
        for (char c : S){   
            if (c == '(')
                close++;
            else if (close > 0)
                close--;
            else
                open++;
        }
        return open + close;
    }
};