// { Driver Code Starts
/* Driver program to test above function */

#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution {
public:
    int maxSubStr(string str){
        //Write your code here
        int zeroCount = 0, oneCount = 0, n = str.size(), ans = 0;
        for(char c: str){
            c=='0' ? zeroCount++ : oneCount++;
            if(zeroCount == oneCount){
                ans++;
                zeroCount = 0;
                oneCount = 0;
            }
        }
        if(zeroCount != 0 || oneCount != 0) return -1;
        return ans;
    }
};


// { Driver Code Starts.
int main()
{
	int t;
	cin>>t;
	while(t--)
	{
	    string str;
	    cin >> str;
	    Solution ob;
	    int ans = ob.maxSubStr(str);
	    cout << ans<<endl;
	}
	return 0;
}
  // } Driver Code Ends