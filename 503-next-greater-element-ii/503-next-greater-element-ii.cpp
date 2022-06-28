class Solution {
public:
    vector<int> nextGreaterElements(vector<int>& nums) {
        int n = nums.size(), i = 1, count = 1;
        stack<int> st;
        vector<int> ans(n);
        st.push(0);
        while(!st.empty()){
            if(i>=n) i=0;
            while(!st.empty()){
                if(st.top() == i){
                    ans[st.top()] = -1;
                    st.pop();
                }
                else if(nums[st.top()] < nums[i]){
                    ans[st.top()] = nums[i];
                    st.pop();
                } 
                else break;
            }
            if(count < n){
                st.push(i);
            }
            i++;
            count++;
        }
        return ans;
    }
};