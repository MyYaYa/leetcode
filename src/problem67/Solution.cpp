class Solution {
public:
    string addBinary(string a, string b) {
        int len_a = a.size();
        int len_b = b.size();
        string result = "";
        int i = len_a - 1;
        int j = len_b - 1;
        int c = 0;
        while (i >= 0 || j >= 0 || c > 0) {
            c += (i>=0 ? (a[i--]-'0') : 0);
            c += (j>=0 ? (b[j--]-'0') : 0);
            result = char(c%2 + '0') + result;
            c = c / 2;
        }
        return result;
    }
};