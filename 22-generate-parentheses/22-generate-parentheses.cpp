class Solution {
public:
    vector<string> ans;
    void generate(int n, int open, int closed, string str){
        if(open+closed >= n){
            if(open==closed)
                ans.push_back(str);
            return;
        }
        if(closed < open) generate(n,open,closed+1,str + ")");
        
        generate(n,open+1,closed,str + "(");
        
    }
    vector<string> generateParenthesis(int n) {
        generate(n*2,0,0,"");
        return ans;
    }
};