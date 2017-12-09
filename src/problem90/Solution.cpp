class Solution {
public:
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        vector<vector<int>> result;
        vector<int> temp;
        backtrack(nums, 0, temp, result);
        return result;
    }

    void backtrack(vector<int>& nums, int start, vector<int>& temp, vector<vector<int>>& result) {
        result.push_back(temp);
        for (int i = start; i < nums.size(); i++) {
            if (i == start || nums[i] != nums[i-1]) {
                temp.push_back(nums[i]);
                backtrack(nums, i+1, temp, result);
                temp.pop_back();
            }
        }
    }
};