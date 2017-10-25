class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        map<int, int> m;
        for (int i = 0; i < nums.size(); i++) {
            int p = target - nums[i];
            if (m.find(p) != m.end()) {
                return vector<int>{m[p], i};
            }
            m[nums[i]] = i;
        }
        return vector<int>();
    }
};