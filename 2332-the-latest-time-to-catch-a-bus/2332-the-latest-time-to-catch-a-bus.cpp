class Solution {
public:
    int latestTimeCatchTheBus(vector<int>& B, vector<int>& P, int capacity) {
        int n = B.size(), m  = P.size(), curr = 0, ans = INT_MIN;
        sort(B.begin(), B.end());
        sort(P.begin(), P.end());
        int i=0, j=0;
        set<int> st;
        for(int x: P){
            st.insert(x);
        }
        while(i<n){
            if(j<m && B[i]>=P[j]){
                curr++;
                if(curr==capacity){
                    int maxTop = P[j];
                    while(st.find(maxTop)!=st.end()){
                        maxTop--;
                    }
                    ans = max(maxTop,ans);
                    i++;
                    curr = 0;
                }
                j++;
            }
            else if(j<m && B[i]<P[j]){
                int maxTop = B[i];
                while(st.find(maxTop)!=st.end()){
                    maxTop--;
                }
                ans = max(maxTop,ans);
                curr = 0;
                i++;
            }
            else{
                int maxTop = B[i];
                while(st.find(maxTop)!=st.end()){
                    maxTop--;
                }
                ans = max(maxTop,ans);
                i++;
            }
        }
        return ans;
    }
};