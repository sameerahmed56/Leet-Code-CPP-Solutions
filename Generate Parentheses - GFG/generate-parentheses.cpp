// { Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;
vector<string> AllParenthesis(int n) ;


 // } Driver Code Ends
//User function Template for C++

// N is the number of pairs of parentheses
// Return list of all combinations of balanced parantheses
class Solution
{
    public:
    vector<string> ans;
    void generate(int n, int open, int closed, string str){
        if(open+closed >= n){
            if(open==closed)
                ans.push_back(str);
            return;
        }
        if(closed < open) generate(n,open,closed+1,str + ")");
        
        generate(n,open+1,closed,str + "(");
        
    }
    vector<string> AllParenthesis(int n) 
    {
        generate(n*2,0,0,"");
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
		int n;
		cin>>n;
		Solution ob;
		vector<string> result = ob.AllParenthesis(n); 
		sort(result.begin(),result.end());
		for (int i = 0; i < result.size(); ++i)
			cout<<result[i]<<"\n";
	}
	return 0; 
} 
  // } Driver Code Ends