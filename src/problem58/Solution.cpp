class Solution {
public:
    int lengthOfLastWord(string s) {
        int len = s.size();
        if (len < 1)
            return 0;
        int nums = 0;
        for (int i = 0; i < len; i++) {
            if (s[i] != ' ') {
                nums++;
            } else if (i+1 < len && s[i+1] != ' ') {
                nums = 0;
            }
        }
        return nums;
    }
};
