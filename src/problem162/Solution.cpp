class Solution {
public:
    int findPeakElement(vector<int>& nums) {
        int len = nums.size();
        if (len <= 1)
            return 0;
        int low = 0, high = len-1;
        while (low < high-1) {
            int mid = (low+high)/2;
            if (nums[mid] > nums[mid-1] && nums[mid] > nums[mid+1]) {
                return mid;
            } else if (nums[mid] < nums[mid+1]) {
                low = mid+1;
            } else {
                high = mid-1;
            }
        }
        return nums[low] > nums[high] ? low : high;
    }
};