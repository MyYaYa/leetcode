class Solution {
public:
    int findMin(vector<int>& nums) {
        int len = nums.size();
        if (len < 1)
            return 0;
        int left = 0;
        int right = len - 1;

        while (left < right-1) {
            if (nums[right] >= nums[left])
                return nums[left];
            int mid = (right + left) / 2;
            if (nums[mid] >= nums[left]) {
                left = mid;
            }
            else {
                right = mid;
            }
        }
        return min(nums[right], nums[left]);
    }
};