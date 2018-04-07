class Solution {
public:
    string ReverseSentence(string str) {
        reverse(str.begin(), str.end());
        int begin = 0;
        for (int i = 0; i < str.size(); ++i) {
            if (str[i] == ' ') {
                reverse(str.begin() + begin, str.begin() + i);
                begin = i + 1;
            }
        }
        if (begin < str.size()) {
            reverse(str.begin() + begin, str.end());
        }
        return str;
    }
};