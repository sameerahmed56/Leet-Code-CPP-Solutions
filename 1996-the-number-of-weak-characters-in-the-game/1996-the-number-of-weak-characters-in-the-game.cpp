class Solution {
public:
    static bool sortcol(const vector<int>& v1, const vector<int>& v2)
    {
        return v1[0] == v2[0] ? v1[1] > v2[1] : v1[0] < v2[0];
    }
    int numberOfWeakCharacters(vector<vector<int>>& prop) {
        int n = prop.size();
        if(n==0) return 0;
        sort(prop.begin(),prop.end(), sortcol);
        int ans = 0;
        stack<int> st;
        st.push(prop[0][1]);
        for(int i=1;i <n; i++){
            // cout << prop[i][0] << "-"<< prop[i][1] << " ";             
            while( !st.empty() &&  st.top() < prop[i][1] ){
                // cout << st.top()  << "-" <<  prop[i][1] << " ";
                st.pop();
                ans++;
            }
            st.push(prop[i][1]);
            // while( !q.empty()){
            //     st.push(q.front());
            //     q.pop();
            // }
        }
        return ans;
    }
};
