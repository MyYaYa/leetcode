class Solution {
public:
    void FindNumsAppearOnce(vector<int> data) {
        if (data.empty())   return;
        vector<int> bitSum(32, 0);
        for (auto i : data) {
            int mask = 1;
            for (int j = 31; j >= 0; --j) {
                int bit = i & mask;
                if (bit != 0)
                    bitSum[j] += 1;
                mask = mask << 1;
            }
        }
        int result = 0;
        for (int i = 0; i < 32; ++i) {
            result = result << 1;
            result += bitSum[i] % 3;
        }
        
    }
};