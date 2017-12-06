class Solution {
public:
    vector<int> grayCode(int n) {
        vector<int> result(1,0);
        for (int i = 1; i <= n; i++) {
            int len = result.size();
            for (int j = len-1; j >= 0; j--) {
                result.push_back(result[j]+(int)pow(2,i-1));
            }
        }
        return result;
    }
};