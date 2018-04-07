class Solution {
public:
    vector<vector<int> > FindContinuousSequence(int sum) {
        vector<vector<int>> result;
        if (sum < 3)   return result;
        int left = 1, right = 2;
        vector<int> tmp = {1,2};
        int now_sum = 3;
        while (left < right) {
            if (now_sum == sum) {
                result.push_back(tmp);
                ++right;
                now_sum += right;
                tmp.push_back(right);
            } else if (now_sum < sum) {
                ++right;
                now_sum += right;
                tmp.push_back(right);
            } else {
                now_sum -= left;
                ++left;
                tmp.erase(tmp.begin());
            }
        }
        return result;
    }
};