class Solution {
public:
    vector<string> wordBreak(string s, unordered_set<string> &dict) {
        if (m.count(s)) return m[s];
        vector<string> result;
        if (dict.find(s) != dict.end())
            result.push_back(s);
        int len = s.size();
        for (int i = 1; i < len; ++i) {
            string word = s.substr(i);
            if (dict.find(word) != dict.end()) {
                string rest = s.substr(0,i);
                vector<string> tmp = combine(word, wordBreak(rest, dict));
                result.insert(result.begin(), tmp.begin(), tmp.end());
            }
        }
        m[s] = result;
        return result;
    }

    vector<string> combine(string word, vector<string> last) {
        for (int i = 0; i < last.size(); ++i) {
            last[i] += (" " + word);
        }
        return last;
    }

private:
    unordered_map<string, vector<string>> m;
};
