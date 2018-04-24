class Solution {
public:
    int ladderLength(string start, string end, unordered_set<string> &dict) {
        if (dict.find(start) == dict.end() || dict.find(end) == dict.end() || start.size() != end.size())
            return 0;
        int res = 1;
        queue<string> q;
        q.push(start);
        dict.erase(start);
        while (!q.empty()) {
            int size = q.size();
            ++res;
            for (int i = 0; i < size; ++i) {
                string top = q.front();
                q.pop();
                for (int j = 0; j < top.size(); ++j) {
                    for (int k = 0; k < 26; ++k) {
                        string temp = top;
                        temp[j] = ('a' + k);
                        if (temp == end)
                            return res;
                        if (dict.find(temp) != dict.end()) {
                            q.push(temp);
                            dict.erase(temp);
                        }
                    }
                }
            }
        }
        return 0;
    }
};
