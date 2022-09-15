class Solution {
public:
    vector<int> findOriginalArray(vector<int>& A) {
        int n = A.size();
        if(n%2!=0 || n == 0) return {};
        vector<int> ans;
        sort(A.begin(),A.end());
        int l = 0, r = 1;
        while(l<n && r < n){
            if(A[l] < 0) l++;
            else if(A[r] < 0 || l>=r) r++;
            else if(A[l]*2 == A[r]){
                ans.push_back(A[l]);
                A[r] = -1; 
                A[l] = -1;
                l++;
                r++;
            }
            else r++;
        }
        if(ans.size() == n/2) return ans;
        return  {};
    }
};