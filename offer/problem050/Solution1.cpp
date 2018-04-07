class Solution {
public:
    string LeftRotateString(string str, int n) {
        if (n <= 0 || n >= str.size()) return str;
        reverse(str.begin(), str.end());
        int index = str.size()-n;
        reverse(str.begin(), str.begin() + index);
        reverse(str.begin() + index, str.end());
        return str;
    }
};