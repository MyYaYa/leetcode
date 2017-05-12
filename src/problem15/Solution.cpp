class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> result;
        if (nums.size() < 3)
            return result;
        vector<int> tmp(3);
        sort(nums.begin(), nums.end());
        auto last = nums.end();
        for (auto i = nums.begin(); i != last-2; i++) {
            if (i > nums.begin() && *i == *(i-1)) continue;
            auto j = i + 1;
            auto k = last - 1;
            while(j < k) {
                if (*i + *j + *k < 0) {
                    j++;
                    while(*j == *(j-1)) j++;
                } else if (*i + *j + *k > 0) {
                    k--;
                    while(*k == *(k+1)) k--;
                } else {
                    tmp[0] = *i;
                    tmp[1] = *j;
                    tmp[2] = *k;
                    result.push_back(tmp);
                    j++;
                    k--;
                    while(j<k && *j==*(j-1) && *k==*(k+1)) {
                        j++;
                        k--;
                    }
                }
            }
        }
    return result;
    }
};