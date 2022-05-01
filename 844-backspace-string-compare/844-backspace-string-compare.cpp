class Solution {
public:
    bool backspaceCompare(string s, string t) {
        stack <char> SS;
        stack <char> TT;
        for(char c: s){
            if(c == '#'){
                if(!SS.empty())
                    SS.pop();
            }
            else
                SS.push(c);
        }
        for(char c: t){
            if(c == '#'){
                if(!TT.empty())
                    TT.pop();
            }
            else
                TT.push(c);
        }
        while(!SS.empty() && !TT.empty()){
            if(SS.top() != TT.top())
                return false;
            
            SS.pop();
            TT.pop();
        }
        if(SS.empty() && TT.empty()){
            return true;
        }
        return false;
        
    }
};