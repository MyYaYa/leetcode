class Solution {
public:
    int findMin(vector<int>& nums) {
        int len = nums.size();
        if (len < 1) {
            return 0;
        }
        int left = 0;
        int right = len - 1;
        while (left < right - 1) {
            if (nums[left] < nums[right])
                return nums[left];
            int mid = (left + right) / 2;
            if (nums[left] < nums[mid]) {
                left = mid;
            } else if (nums[left] > nums[mid]) {
                right = mid;
            } else {
                left++;
            }
        }
        return min(nums[left], nums[right]);
    }
};