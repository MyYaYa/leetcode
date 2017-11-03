class Solution {
public:
    vector<vector<int>> combine(int n, int k) {
        vector<vector<int>> result;
        vector<int> combination;
        dfs(result, combination, 1, k, n);
        return result;
    }
    void dfs(vector<vector<int>>& result, vector<int>& combination, int begin, int k_temp, int n) {
        if (k_temp < 0 || begin > n+1)
            return;
        if (k_temp == 0 && begin <= n+1) {
            result.push_back(combination);
            return;
        }
        for (int i = begin; i <= n; i++) {
            combination.push_back(i);
            dfs(result, combination, i+1, k_temp-1, n);
            combination.pop_back();
        }
    }
};
