class Solution {
public:
    string getPermutation(int n, int k) {
        if (n == 0)
            return "";
        if (n == 1)
            return "1";
        vector<int> r;
        for (int i = 1; i <= n; i++) {
            r.push_back(i);
        }
        k--;
        while(k > 0) {
            int index = n-2;
            while (index>0 && r[index]>r[index+1]) index--;
            for (int i = n-1; i > index; i--) {
                if (r[i] > r[index]) {
                    swap(r[i], r[index]);
                    break;
                }
            }
            sort(r.begin() + index+1, r.end());
            k--;
        }
        string result = "";
        for (auto i : r) {
            result = result + to_string(i);
        }
        return result;
    }

    void swap(int& a, int& b) {
        int temp = a;
        a = b;
        b = temp;
    }
};