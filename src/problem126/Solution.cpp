class Solution {
public:
    vector<vector<string>> findLadders(string start, string end, vector<string> &wordlist) {
        vector<vector<string>> res;
        if (start.size() != end.size())
            return res;
        unordered_set<string> dict(wordlist.begin(), wordlist.end());
        queue<vector<string>> paths;
        paths.push({start});

        unordered_set<string> visited;

        bool cont = true;

        while (!paths.empty() && cont) {
            int size = paths.size();
            for (string str : visited)
                dict.erase(str);
            visited.clear();
            for (int i = 0; i < size; ++i) {
                vector<string> path = paths.front();
                paths.pop();
                string last = path.back();
                for (int j = 0; j < last.size(); ++j) {
                    for (int k = 0; k < 26; ++k) {
                        string temp = last;
                        temp[j] = 'a' + k;

                        if (dict.find(temp) != dict.end()) {
                            visited.insert(temp);
                            vector<string> newPath(path.begin(), path.end());
                            newPath.push_back(temp);
                            if (temp == end) {
                                cont = false;
                                res.push_back(newPath);
                            }
                            paths.push(newPath);
                        }
                    }
                }
            }
        }
        return res;
    }
};
