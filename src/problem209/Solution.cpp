class Solution {
public:
    int minSubArrayLen(int s, vector<int>& nums) {
        int len = nums.size();
        int low = 0;
        int result = INT_MAX;
        int sum = 0;
        for (int i = 0; i < len; i++) {
            sum += nums[i];
            while (sum >= s) {
                result = min(result, i-low+1);
                sum -= nums[low];
                low++;
            }
        }
        return result==INT_MAX ? 0 : result;
    }
};