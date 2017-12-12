class Solution {
public:
    vector<string> restoreIpAddresses(string s) {
        if (s.empty())  return vector<string>();
        int len = s.size();
        if (len > 12)   return vector<string>();
        vector<string> result;
        string temp = "";
        backtrack(s, 0, 0, temp, result);
        return result;
    }

    void backtrack(string s, int start, int count, string temp, vector<string>& result) {
        if (count > 4) return;
        if (count == 4 && start == s.size()) {
            result.push_back(temp);
            return;
        }
        for (int i = 0; i < 3; i++) {
            if (start + i >= s.size())  break;
            string sub = s.substr(start, i+1);
            if ((sub[0] == '0' && sub.size() > 1) || (i == 2 && stoi(sub) > 255))   break;
            backtrack(s, start+i+1, count+1, temp+sub+(count < 3 ? '.' : '\0'), result);
        }
    }
};