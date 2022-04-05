class Solution {
public:
    int maxArea(vector<int>& height) {
        int ans = 0, n = height.size(), l =0, r=n-1;
        while(l<r){
            int h = min(height[l],height[r]);
            ans = max(h*(r-l),ans);
            while(height[l]<= h && l<r)l++;
            while(height[r]<= h && l<r)r--;
        }
        return ans;
    }
};