class Solution {
public:
    void reverseWords(string &s) {
        int i=0, j=0;
        int b_index = 0;
        while (1) {
            while (s[i] == ' ') i++;
            if (i == s.size())  break;
            if (j != 0) s[j++] = ' ';
            b_index = j;
            while (i < s.size() && s[i] != ' ') {
                s[j++] = s[i++];
            }
            reverse(s.begin()+b_index, s.begin()+j);
            b_index = j;
        }
        s.resize(j);
        reverse(s.begin(), s.begin() + j);
    }
};