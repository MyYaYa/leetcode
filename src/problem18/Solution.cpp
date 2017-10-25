class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        vector<vector<int>> result;
        int len = nums.size();
        if (len < 4) {
            return result;
        }
        sort(nums.begin(), nums.end());
        for (int i = 0; i < len-3; i++) {
            if (i>0 && nums[i-1] == nums[i])
                continue;
            if (nums[i] + nums[i+1] + nums[i+2] + nums[i+3] > target)
                break;
            if (nums[i] + nums[len-3] + nums[len-2] + nums[len-1] < target)
                continue;
            for (int j = i+1; j < len-2; j++) {
                if (j > i+1 && nums[j] == nums[j-1])
                    continue;
                if (nums[i] + nums[j] + nums[j+1] + nums[j+2] > target)
                    break;
                if (nums[i] + nums[j] + nums[len-2] + nums[len-1] < target)
                    continue;
                int k = j+1;
                int l = len-1;
                while (k < l) {
                    if (k>j+1 && nums[k] == nums[k-1]) {
                        k++;
                        continue;
                    }
                    if (l<len-1 && nums[l] == nums[l+1]){
                        l--;
                        continue;
                    }
                    if (nums[i] + nums[j] + nums[k] + nums[l] > target)
                        l--;
                    else if (nums[i] + nums[j] + nums[k] + nums[l] < target)
                        k++;
                    else {
                        vector<int> tmp = {nums[i], nums[j], nums[k], nums[l]};
                        result.push_back(tmp);
                        k++;
                        l--;
                    }
                }
            }
        }
        return result;
    }
};