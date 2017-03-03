public class Solution {
	public List<List<Integer>> threeSum(int[] nums) {
		List<List<Integer>> lists = new ArrayList<>();
        Arrays.sort(nums);

        for (int i = 0; i < len-2; i++) {
            if (nums[i] > 0 || nums[len-1] < 0)
                break;;
            if (i > 0 && nums[i] == nums[i-1])
                continue;
            int j = i + 1;
            int k = len - 1;
            while (j < k) {
                if (nums[k] < 0)
                    break;
                int sum = nums[i] + nums[j] + nums[k];
                if (sum == 0) {
                    List<Integer> list = new ArrayList<>();
                    list.add(nums[i]);
                    list.add(nums[j]);
                    list.add(nums[k]);
                    lists.add(list);
                    ++j;
                    --k;
                    while (j < k && nums[j] == nums[j-1])
                        ++j;
                    while (j < k && nums[k] == nums[k+1])
                        --k;
                }
                else if (sum < 0) {
                    ++j;
                }
                else {
                    --k;
                }
            }
        }
        return lists;
	}
}