class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        if (nums.empty())   return 0;
        int l = 0;
        for (int r = 0; r < nums.size(); r++) {
            if (nums[r] != val) {
                nums[l++] = nums[r];
            }
        }
        return l;
    }
};