class Solution {
public:
    vector<int> twoOutOfThree(vector<int>& nums1, vector<int>& nums2, vector<int>& nums3) {
        unordered_map<int,unordered_set<int>>st;
        for(int i=0;i<nums1.size();i++){
            st[nums1[i]].insert(1);
        }
        for(int i=0;i<nums2.size();i++){
            st[nums2[i]].insert(2);
        }
        for(int i=0;i<nums3.size();i++){
            st[nums3[i]].insert(3);
        }
        vector<int>result;
        for(auto it=st.begin();it!=st.end();it++){
            if(it->second.size()>=2)
            {
                result.push_back(it->first);
            }
        }
        return result;
    }
};