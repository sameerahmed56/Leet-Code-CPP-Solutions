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
	    while(j < m && arr[0][j] != 1){
	        j++;
	    }
	    if(j!=m){
	        maxCount = m-j;
	        ans = i;
	    }
	    else j = m-1;
	    
	    for( i=1; i<n; i++){
	        if(j >= 0 && arr[i][j] == 1){
	            while(j >= 0 && arr[i][j] == 1){
	                j--;
	            }
	            j++;
	            if(m-j>maxCount){
	                ans = i;
	                maxCount = m-j;
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