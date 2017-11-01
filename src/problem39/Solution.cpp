class Solution {
public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        int len = candidates.size();
        
        vector<vector<int>> res;
        if (len < 1) {
            return res;
        }
        vector<int> combination;
        sort(candidates.begin(), candidates.end());
        func(candidates, target, 0, res, combination);
        return res;
    }
    void func(vector<int>& candidates, int target, int begin, vector<vector<int>>& res, vector<int>& combination) {
        if (target == 0) {
            res.push_back(combination);
            return;
        }
        for (int i = begin; i<candidates.size() && candidates[i]<=target; i++) {
            combination.push_back(candidates[i]);
            func(candidates, target-candidates[i], i, res, combination);
            combination.pop_back();
        }
    }
};