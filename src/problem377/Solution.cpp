class Solution {
public:
    int combinationSum4(vector<int>& nums, int target) {
        sort(nums.begin(), nums.end());
        int res[target+1];
        fill_n(res, target+1 ,0);
        for (int i = 1; i <= target; i++) {
            for (int j = 0; j < nums.size(); j++) {
                if (nums[j] > i)
                    break;
                if (nums[j] == i)
                    res[i]++;
                else
                    res[i] += res[i-nums[j]];
            }
        }
        return res[target];
    }
};