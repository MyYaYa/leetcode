class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        for (auto it = nums.begin(); it != nums.end(); ) {
            if (*it == val) {
                *it = nums.back();
                nums.pop_back();
            } else {
                it++;
            }
        }
        return nums.size();
    }
};