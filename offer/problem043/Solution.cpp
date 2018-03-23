class Solution {
public:
    int FirstNotRepeatingChar(string str) {
        if (str.empty())    return -1;
        const int ascii_size = 128;
        int hash_table[ascii_size];
        memset(hash_table, 0, ascii_size * 4);
        for (auto i : str) {
            ++hash_table[i];
        }
        for (int index = 0; index < str.size(); ++index) {
            if (hash_table[str[index]] == 1) {
                return index;
            }
        }
        return -1;
    }
};