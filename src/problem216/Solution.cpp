class Solution {
public:
    vector<vector<int>> combinationSum3(int k, int n) {
        vector<vector<int>> result;
        vector<int> combination;
        dfs(result, combination, 1, k, n);
        return result;
    }

    void dfs(vector<vector<int>>& result, vector<int>& combination, int begin, int k_temp, int new_target) {
        if (k_temp < 0 || new_target < 0)
            return;
        if (k_temp == 0 && new_target != 0)
            return;
        if (k_temp == 0 && new_target == 0) {
            result.push_back(combination);
        }
        for (int i = begin; i < 10; i++) {
            combination.push_back(i);
            dfs(result, combination, i+1, k_temp-1, new_target-i);
            combination.pop_back();
        }
    }
};