class Solution {
public:
    string countAndSay(int n) {
        int curr = 1;
        string curr_str = "1";
        while (curr < n) {
            curr++;
            string newString;
            char curr_char = ' ';
            int count = 0;
            for (int i = 0; i < curr_str.size(); i++) {
                if (curr_str[i] == curr_char) {
                    count++;
                } else {
                    if (curr_char != ' ') {
                        newString.push_back('1' + count - 1);
                        newString.push_back(curr_char);
                    }
                    curr_char = curr_str[i];
                    count = 1;
                }
            }
            newString.push_back('1' + count - 1);
            newString.push_back(curr_char);
            curr_str = newString;
        }

        return curr_str;
    }
};