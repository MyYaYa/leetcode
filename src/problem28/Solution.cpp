class Solution {
public:
    int strStr(string haystack, string needle) {
        if (needle=="") return 0;
        if (haystack=="")   return -1;
        int len_h = haystack.size();
        int len_n = needle.size();
        int i = 0;
        int k=0;
        int index = -1;
        while (i < len_h) {
            if (haystack[i] == needle[k]) {
                if (k == len_n-1) {
                    index = i-k;
                    break;
                }
                k++;
            }
            else {
                if (i-k > len_h-len_n)    break;
                i = i - k;
                k = 0;
            }
            i++;
        }
        return index;
    }
};