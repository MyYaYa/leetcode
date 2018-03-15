class Solution {
public:
    int jump(vector<int>& nums) {
        if (nums.empty())   return 0;
        int curEnd = 0, i = 0, curFarthest = 0, jump = 0;
        for (; i < nums.size() - 1; ++i) {
            curFarthest = max(curFarthest, i + nums[i]);
            if (i == curEnd) {
                jump++;
                curEnd = curFarthest;
            }
        }
        return jump;
    }
};
