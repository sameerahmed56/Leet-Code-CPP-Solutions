class Solution {
public:
    int convertTime(string current, string correct) {
        int diff = 0, ans = 0;
        int currHour= stoi(current.substr(0, 2)), currMin= stoi(current.substr(3, 2));
        int corrHour= stoi(correct.substr(0, 2)), corrMin= stoi(correct.substr(3, 2));
        diff += (corrHour-currHour)*60;
        diff += corrMin-currMin;
        ans += diff/60;
        diff = diff%60;
        ans += diff/15;
        diff = diff%15;
        ans += diff/5;
        diff = diff%5;
        ans += diff;
        return ans;
    }
};