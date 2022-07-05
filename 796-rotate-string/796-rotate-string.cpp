class Solution {
public:
    bool rotateString(string s, string goal) {
        queue<char> q1, q2;
        int n = s.size();
        if(n != goal.size()) return false;
        
        for(int i =0; i<n; i++){
            q1.push(s[i]);
            q2.push(goal[i]);
        }
        while (n--) {
            char ch = q2.front();
            q2.pop();
            q2.push(ch);
            if (q2 == q1)
                return true;
        }
        return false;
    }
};