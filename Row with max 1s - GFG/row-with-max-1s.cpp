// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
//User function template for C++
class Solution{
public:
	int rowWithMax1s(vector<vector<int> > arr, int n, int m) {
	    // code here
	    int i = 0, j = 0, ans = -1, maxCount = 0;;
	    bool found = false;
	    for(;i<n && !found ;i++){
	        j = 0;
	        while(j < m && arr[i][j] != 1){
	            j++;
	        }
	        if(j!=m){
	            found = true;
	            maxCount = n-j;
	            ans = i;
	        }
	    }
	    // j = 1
	    if(!found) return -1;
	    for( ;i<n; i++){
	        if(j >= 0 && arr[i][j] == 1){
	            while(j >= 0 && arr[i][j] == 1){
	                j--;
	            }
	            j++;
	            if(n-j>maxCount){
	                ans = i;
	                maxCount = n-j;
	            }
	        }
	    }
	    return ans;
	}

};

// { Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, m;
        cin >> n >> m;
        vector< vector<int> > arr(n,vector<int>(m));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                cin>>arr[i][j];
            }
        }
        Solution ob;
        auto ans = ob.rowWithMax1s(arr, n, m);
        cout << ans << "\n";
    }
    return 0;
}
  // } Driver Code Ends