class Solution {
public:
    void replaceSpace(char *str,int length) {
        if (str == nullptr || length <= 0)  return;

        int actual_len = 0, new_len = 0;
        int i = 0;
        while (str[i] != '\0') {
            actual_len++;
            if (str[i] == ' ')    new_len +=3;
            else    new_len++;
            i++;
        }

        if (new_len > length)   return;
        while (actual_len >= 0 && new_len > actual_len) {
            if (str[actual_len] == ' ') {
                str[new_len--] = '0';
                str[new_len--] = '2';
                str[new_len--] = '%';
            } else {
                str[new_len--] = str[actual_len];
            }
            actual_len--;
        }
    }
};