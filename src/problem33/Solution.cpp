class Solution {
public:
    int search(vector<int>& nums, int target) {
        int len = nums.size();
        if (len == 0)
            return -1;
        int low = 0;
        int high = len-1;
        while (low < high) {
            int mid = (high+low) / 2;
            if (nums[mid] == target)
                return mid;
            if (nums[mid] >= nums[low]) {
                if (nums[mid] > target && nums[low] <= target) {
                    high = mid-1;
                }
                else {
                    low = mid+1;
                }
            } else {
                if (nums[mid] < target && nums[high] >= target) {
                    low = mid+1;
                } else {
                    high = mid-1;
                }
            }
        }
        return (nums[low] == target) ? low : -1;
    }
};