class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int one_out = 0, two_out = 0;
        for (auto i : nums) {
            one_out = (i ^ one_out) & (~two_out);
            two_out = (i ^ two_out) & (~one_out);
        }
        return one_out;
    }
};