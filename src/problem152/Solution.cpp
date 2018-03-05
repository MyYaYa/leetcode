class Solution {
public:
    int maxProduct(vector<int>& nums) {
        if (nums.empty())   return 0;
        int len = nums.size();
        int r = nums[0];
        for (int i = 1, imax = r, imin = r; i < len; i++) {
            if (nums[i] < 0)
                swap(imax, imin);

            imax = max(nums[i], imax * nums[i]);
            imin = min(nums[i], imin * nums[i]);
            r = max(r, imax);
        }
        return r;
    }
};