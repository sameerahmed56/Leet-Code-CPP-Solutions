// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

int countRev (string s);
int main()
{
    int t; cin >> t;
    while (t--)
    {
        string s; cin >> s;
        cout << countRev (s) << '\n';
    }
}

// Contributed By: Pranay Bansal// } Driver Code Ends



int countRev (string s)
{
    // your code here
    if(s.size()%2 != 0) return -1;
    int count = 0, ans = 0;
    for(char c: s){
        if(c == '{'){
            count++;
        }
        else{
            if(count == 0){
                ans++;
                count++;
            }
            else{
                count--;
            }
        }
        // cout << count <<  " ";
    }
    // if(count%2 != 0) return -1;
    return ans + (count/2);
}