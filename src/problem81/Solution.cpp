class Solution {
public:
    bool search(vector<int>& nums, int target) {
        int len = nums.size();
        if (len == 0)
            return false;
        int low = 0;
        int high = len-1;
        while (low < high) {
            int mid = (high+low) / 2;
            if (nums[mid] == target)
                return true;
            if (nums[mid] > nums[low]) {
                if (nums[mid] > target && nums[low] <= target) {
                    high = mid-1;
                }
                else {
                    low = mid+1;
                }
            } else if (nums[mid] < nums[low]) {
                if (nums[mid] < target && nums[high] >= target) {
                    low = mid+1;
                } else {
                    high = mid-1;
                }
            } else {
                low++;
            }
        }
        return nums[low] == target;
    }
};