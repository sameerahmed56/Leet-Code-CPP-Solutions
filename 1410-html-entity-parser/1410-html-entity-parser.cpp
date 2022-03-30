class Solution {
public:
    string entityParser(string text) {
        unordered_map<string, string> mp;
        mp["&quot;"] = "\"";
        mp["&apos;"] = "'";
        mp["&amp;"] = "&";
        mp["&gt;"] = ">";
        mp["&lt;"] = "<";
        mp["&frasl;"] = "/";
        int n = text.size(), pos = 0;
        string temp = "", ans = "";
        bool canBeSpecial = false;
        while(pos < n){
            if(text[pos] == ';'){
                canBeSpecial = false;
                temp += text[pos];
                if(mp.find(temp) != mp.end()){
                    temp = mp[temp];
                }
                ans += temp;
                temp =  "";
            }
            else if(text[pos] == '&' && canBeSpecial){
                ans+=temp;
                temp = text[pos];
            }
            else if(text[pos] == '&'  || canBeSpecial){
                temp += text[pos];
                canBeSpecial = true;
            }
            else{
                ans += text[pos];
            }
            pos++;
        }
        ans += temp;
        return ans;
    }
};