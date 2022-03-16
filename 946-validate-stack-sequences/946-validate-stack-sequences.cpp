class Solution {
public:
    bool validateStackSequences(vector<int>& pushed, vector<int>& popped) {
        stack<int> st;
        unordered_set <int> intSet ;
        int pop = 0, pus = 0;
        while(pop<popped.size()){
            cout <<pop << " ";
            int key  = popped[pop];
            if(pus < pushed.size() && pushed[pus] == key){
                pop++;
                pus++;
            }
            else if(intSet.find(key) != intSet.end()){
                if(st.top() == key){
                    st.pop();
                    pop++;
                }
                else{
                    return false;
                }
            }
            else{
                st.push(pushed[pus]);
                intSet.insert(pushed[pus]);
                pus++;
            }
        }
        return true;
        
    }
};