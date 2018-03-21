struct Less{
    bool operator() (int a, int b) {
        string ab = to_string(a) + to_string(b);
        string ba = to_string(b) + to_string(a);
        char* c_ab = (char *)malloc(ab.size());
        char* c_ba = (char *)malloc(ba.size());
        strcpy(c_ab, ab.c_str());
        strcpy(c_ba, ba.c_str());
        if (strcmp(c_ab, c_ba) <= 0) {
            return true;
        } else {
            return false;
        }
    }
};

class Solution {
public:
    string PrintMinNumber(vector<int> numbers) {
        sort(numbers.begin(), numbers.end(), Less());
        string result = "";
        for (auto i : numbers) {
            result += to_string(i);
        }
        return result;
    }
};