class Solution {
public:
    vector<int> twoOutOfThree(vector<int>& nums1, vector<int>& nums2, vector<int>& nums3) {
        unordered_map<int,int>st;
        for(int i=0;i<nums1.size();i++){
            st[nums1[i]] = 1;
        }
        for(int i=0;i<nums2.size();i++){
            if(st[nums2[i]] == 1 || st[nums2[i]] == 2){
                st[nums2[i]] = 2;
            } 
            else{
                st[nums2[i]] = -1;
            }
        }
        for(int i=0;i<nums3.size();i++){
            if(st[nums3[i]] == 1 || st[nums3[i]] == -1 ||  st[nums3[i]] == 2){
                st[nums3[i]] = 2;
            }
            else{
                st[nums3[i]] = 0;        
            }
        }
        vector<int>result;
        for(auto it=st.begin();it!=st.end();it++){
            if(it->second>=2)
            {
                result.push_back(it->first);
            }
        }
        return result;
    }
};