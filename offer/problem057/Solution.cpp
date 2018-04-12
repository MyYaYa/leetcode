class Solution {
public:
    vector<int> multiply(const vector<int>& A) {
        int len = A.size();
        vector<int> result;
        if (len < 1)    return result;
        result = vector<int>(len, 0);
        result[0] = 1;
        for (int i = 1; i < len; ++i) {
            result[i] = result[i-1] * A[i-1];
        }
        int temp = 1;
        for (int i = len-2; i >= 0; --i) {
            temp *= A[i+1];
            result[i] *= temp;
        }
        return result;
    }
};