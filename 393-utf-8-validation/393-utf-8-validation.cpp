class Solution {
public: 
    bool nextKBytes(int &i,vector<int> &data,int k,int n)
    {
        if(i >= n-k)return false;
        int j = 0;
        while(j < k)
        {   
            i++;
            if(data[i] < 128||data[i] >= 192)return false;
            j++;
        }
        return true;
    }
    bool validUtf8(vector<int>& data) {
       int n = data.size();
        for(int i = 0;i < n;i++)
        {
            if(data[i]>191)
            {   
                if(data[i] > 247)return false;
                if(data[i] > 239)
                {   
                    if(!nextKBytes(i,data,3,n))return false;
                }
                else if(data[i] > 223)
                {
                    if(!nextKBytes(i,data,2,n))return false;
                }
                else if(data[i] > 191)
                {
                    if(!nextKBytes(i,data,1,n))return false;
                }
                else false;

            }
            else if(data[i] >= 128 && data[i] < 192)return false;
        }
        
        return true;    
    }
};