class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        if (nums.empty())
            return 0;

        int l = 0;
        for (int r = 1; r < nums.size(); r++) {
            if (nums[r] == nums[l])
                continue;
            nums[++l] = nums[r];
        }

        return l + 1;
    }
};