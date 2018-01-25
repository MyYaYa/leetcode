class Solution {
public:
    vector<vector<string>> partition(string s) {
        vector<vector<string>> result;
        int size = s.size();
        if (size == 0) return result;
        vector<string> temp_v;
        dfs(s, result, temp_v, 0, 0);
        return result;
    }

    void dfs(string s, vector<vector<string>>& result, vector<string>& temp_v, int begin, int end) {
        if (end >= s.size())
            return;
        if (palindrome(s, begin, end)) {
            temp_v.push_back(s.substr(begin, end-begin+1));
            if (end == s.size()-1) {
                result.push_back(temp_v);
            }
            dfs(s, result, temp_v, end+1, end+1);
            temp_v.pop_back();
            dfs(s, result, temp_v, begin, end+1);
        } else {
            dfs(s, result, temp_v, begin, end+1);
        }
    }

    bool palindrome(string s, int begin, int end) {
        while (begin <= end) {
            if (s[begin] != s[end])   return false;
            else {
                begin++;
                end--;
            }
        }
        return true;
    }
};