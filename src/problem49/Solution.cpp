class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        vector<vector<string>> result;
        multimap<string, string> m;
        for (string str : strs) {
            string str_temp = str;
            sort(str_temp.begin(), str_temp.end());
            m.insert(make_pair(str_temp, str));
        }
        multimap<string, string>::iterator iter;
        pair<multimap<string, string>::iterator, multimap<string, string>::iterator> p;
        for (iter = m.begin(); iter != m.end();) {
            p = m.equal_range(iter->first);
            vector<string> sub;
            for (iter=p.first; iter!=p.second; iter++) {
                sub.push_back(iter->second);
            }
            result.push_back(sub);
        }
        return result;
    }
};