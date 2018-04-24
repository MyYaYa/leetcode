class Solution {
public:
    string longestPalindrome(string s) {
        if (s.size() == 0)  return "";
        string temp = "#";
        for (int i = 0; i < s.size(); ++i) {
            temp += s[i];
            temp += "#";
        }
        vector<int> p(temp.size(), 0);
        p[0] = 1;
        int pR = 1, index = 0;
        for (int i = 1; i < temp.size(); ++i) {
            // Situation1: do the normal operation
            if (i >= pR) {
                int l = i, r = i;
                int R = 0;
                while (l>=0 && r < temp.size() && temp[l] == temp[r]) {
                    --l;
                    ++r;
                    ++R;
                }
                p[i] = R;
                if (i + R > pR) {
                    pR = i + R;
                    index = i;
                }
            } else {
                // Situation2: use already known info to accelerate
                int sym_i = 2 * index - i;
                int sym_R = p[sym_i];
                if (i + sym_R < pR) {
                    p[i] = sym_R;
                } else if (i + sym_R > pR) {
                    p[i] = pR - i;
                } else {
                    int r = pR, l = 2*i-pR;
                    int R = sym_R;
                    while (l>=0 && r < temp.size() && temp[l] == temp[r]) {
                        --l;
                        ++r;
                        ++R;
                    }
                    p[i] = R;
                }
                if (i + p[i] > pR) {
                    pR = i + p[i];
                    index = i;
                }
            }
        }
        int longest = -1;
        int center = -1;
        for (int i = 0; i < temp.size(); ++i) {
            if (p[i] > longest) {
                longest = p[i];
                center = i;
            }
        }
        int l = center - (longest-1), r = center + (longest - 1) - 1;
        return s.substr(l/2, r/2 - l/2 + 1);
    }
};
