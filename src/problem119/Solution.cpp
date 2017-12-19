class Solution {
public:
    vector<int> getRow(int rowIndex) {
        vector<int> pre(1,1);
        vector<int> result;
        for (int i = 0; i <= rowIndex; i++) {
            result = vector<int>(i+1, 1);
            for (int j = 1; j < i; j++) {
                result[j] = pre[j-1] + pre[j];
            }
            pre = result;
        }
        return result;
    }
};