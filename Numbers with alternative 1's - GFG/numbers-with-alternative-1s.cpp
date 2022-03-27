// { Driver Code Starts


#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends


class Solution{
	public:
	vector<int> ans;
	void generate(int n,int len ,bool lastOne, int last, int currSum){
	    if(len <= n && currSum > 0 && lastOne){
	        ans.push_back(currSum);
	    }
	    if(len>=n)return;
	    if(len>0){
	        last = last<<1;
	    }
	   // cout << last << " ";
	    if(!lastOne)generate(n,len+1,true,last,currSum + last);
	    generate(n,len+1,false,last,currSum);
	}
	vector<int>numberWithNoConsecutiveOnes(int n){
	    generate(n,0,false,1,0);
	    sort(ans.begin(),ans.end());
	    return ans;
	}
};

// { Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int n;
		cin >> n;
		Solution ob;
		vector<int>ans = ob.numberWithNoConsecutiveOnes(n);
		for(auto i: ans)
			cout << i <<" ";
		cout << "\n";
	}
	return 0;
}  // } Driver Code Ends