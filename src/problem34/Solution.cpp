class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        int len = nums.size();
        if (len < 1)
            return vector<int>{-1,-1};
        int left = 0;
        int right = len-1;
        vector<int> result;
        while (left < right-1) {
            if (target < nums[0] || target > nums[len-1])
                return vector<int>{-1,-1};
            int mid = (left+right)/2;
            if (nums[mid] < target) {
                left = mid+1;
            } else if (nums[mid] > target) {
                right = mid - 1;
            } else {
                int temp = mid;
                while (temp<len && nums[temp] == target) {temp++;}
                while (mid>=0 && nums[mid] == target) {mid--;}
                result.push_back(++mid);
                result.push_back(--temp);
                return result;
            }
        }
        for(int i = left; i <= right; i++) {
            if (nums[i]==target) {
                result.push_back(i);
                int temp = i;
                while (temp<len && nums[temp]==target) {temp++;}
                result.push_back(--temp);
                return result;
            }
        }
        return vector<int>{-1,-1};
    }
};