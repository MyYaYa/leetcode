class Solution {
public:
    vector<int> singleNumber(vector<int>& nums) {
        int diff = 0;
        for (int i = 0; i < nums.size(); ++i) {
            diff ^= nums[i];
        }

        diff &= -diff;
        vector<int> ret = {0 ,0};
        for (int i = 0; i < nums.size(); ++i) {
            if ((nums[i]&diff) > 0)
                ret[0] ^= nums[i];
            else
                ret[1] ^= nums[i];
        }
        return ret;
    }
};
