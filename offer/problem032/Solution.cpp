class Solution {
public:
    vector<string> Permutation(string str) {
        if (str.empty())    return vector<string>();
        vector<string> result;
        string temp = "";
        Permutation(str, temp, result);
        return result;
    }

    void Permutation(string str, string temp, vector<string>& result) {
        if (str.empty()) {
            result.push_back(temp);
            return;
        }
        set<char> set;
        for (int i = 0; i < str.size(); i++) {
            if (set.find(str[i]) != set.end())
                continue;
            set.insert(str[i]);
            temp += str[i];
            string rest = str;
            Permutation(rest.erase(i,1), temp, result);
            temp.pop_back();
        }
    }
};