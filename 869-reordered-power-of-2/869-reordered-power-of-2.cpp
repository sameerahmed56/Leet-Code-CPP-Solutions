class Solution {
public:
    bool checkChar(vector<int> arr, int cur){
        int sz =  to_string(cur).size();
        string s = to_string(cur);
        for(char c: s){
            if( arr[c-'0'] == 0) return false;
            arr[c-'0'] -= 1;
        }
        return true;
    }
    bool reorderedPowerOf2(int n) {
        string s = to_string(n);
        int m = s.size();
        vector<int> arr(26,0);
        for(char c: s){
            arr[c-'0'] += 1;
        }
        int cur = 1;
        int sz = to_string(cur).size();
        while(sz<m){
            cur = cur << 1;
            sz = to_string(cur).size();
        }
        while(sz == m){
            if(checkChar(arr,cur)){
                cout << cur << " ";
                return true;
            }
            cur = cur << 1;
            sz = to_string(cur).size();
        }
        return false;
    }
};