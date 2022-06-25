// { Driver Code Starts
//Initial Template for Java
import java.io.*;
import java.util.*; 
class GFG{
    public static void main(String args[]) throws IOException { 
        BufferedReader read = new BufferedReader(new InputStreamReader(System.in));
        int t = Integer.parseInt(read.readLine().trim());
        while(t-- > 0){
            String s = read.readLine().trim();
            Solution ob = new Solution();
            System.out.println(ob.firstRepChar(s));
        }
    }
}// } Driver Code Ends


//User function Template for Java
class Solution 
{ 
    String firstRepChar(String s) 
    { 
        // code here
        int n = s.length();
        boolean isRepeated = false;
        HashMap<Character, Integer> mp = new HashMap<>();
        for(int i=0;i<n;i++){
            if(mp.containsKey(s.charAt(i))){
                isRepeated = true;
                return String.valueOf(s.charAt(i));
            }
            else mp.put(s.charAt(i),i);
        }
        return "-1";
    }
} 