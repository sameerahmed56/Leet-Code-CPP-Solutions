class Solution {
public:
    static bool sortcol(const vector<int>& v1, const vector<int>& v2)
    {
        return v1[0] == v2[0] ? v1[1] > v2[1] : v1[0] < v2[0];
    }
    int numberOfWeakCharacters(vector<vector<int>>& prop) {
        int n = prop.size(), ans = 0;
        if(n==0) return 0;
        sort(prop.begin(),prop.end(), sortcol);
        stack<int> st;
        for(int i=0;i <n; i++){
            while(!st.empty() &&  st.top() < prop[i][1] ){
                st.pop();
                ans++;
            }
            st.push(prop[i][1]);
        }
        return ans;
    }
};
