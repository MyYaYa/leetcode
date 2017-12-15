class Solution {
public:
    string simplifyPath(string path) {
        vector<string> s;
        string temp;
        path.push_back('/');
        for (auto i : path) {
            if (i == '/') {
                if (temp == "..") {
                    if (s.size() > 0)
                        s.pop_back();
                } else if (temp == "." || temp == "") {
                } else {
                    s.push_back(temp);
                }
                temp.clear();
            } else {
                temp.push_back(i);
            }
        }
        string res;
        for (auto i : s) {
            res += ("/" + i);
        }
        return s.size()==0 ? "/" : res;
    }
};