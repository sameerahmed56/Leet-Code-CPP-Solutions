class Solution {
public:
    int binarySearch(vector<int>& arr, int l, int r, int x, int& pos)
    {
        if (r >= l) {
            int mid = l + (r - l) / 2;
            pos = mid;
            if (arr[mid] == x){
                return mid;
            }
            if (arr[mid] > x){
                return binarySearch(arr, l, mid - 1, x, pos);
            }
            return binarySearch(arr, mid + 1, r, x, pos);
        }
        return -1;
    }
    vector<int> findClosestElements(vector<int>& arr, int k, int x) {
        int pos = 0, n = arr.size();
        int find = binarySearch(arr,0,n-1,x,pos);
        if(find == -1){
            int curMin = abs(arr[pos]-x);
            if(pos >0 && abs(arr[pos-1]-x) <= curMin){
                curMin = abs(arr[pos-1]-x);
                pos = pos-1;
            }
            if(pos<n-1 && abs(arr[pos+1]-x) < curMin){
                pos = pos+1;
            }
        }
        int l = pos, r = pos;
        while(k>1){
            int mini = INT_MAX;
            bool dec = 0;
            if(l>0){
                mini = abs(arr[l-1]-x);
                dec = 1;
            }
            if(r<n-1 && abs(arr[r+1]-x) < mini){
                dec = 0;
            }
            if(dec) l--;
            else r++;
            k--;
        }
        vector<int> ans(arr.begin()+l, arr.begin()+r+1);
        return ans;
    }
};