public class Solution {
    public int threeSumClosest(int[] nums, int target) {
        Arrays.sort(nums);
        int len = nums.length;
        int result = nums[0] + nums[1] + nums[len-1];
        for (int i = 0; i < len-2; i++) {
            int start = i + 1;
            int end = len - 1;
            while (start < end) {
                int sum = nums[i] + nums[start] + nums[end];
                if (sum == target)  return sum;
                else if (sum < target)   start++;
                else    end--;
                if (Math.abs(sum - target) < Math.abs(result - target)) result = sum;
            }
        }
        return result;
    }
}