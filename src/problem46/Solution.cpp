class Solution {
public:
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> result;
        sort(nums.begin(), nums.end());
        result.push_back(nums);
        while (next(nums)) {
            result.push_back(nums);
        }
        return result;
    }

    bool next(vector<int>& nums) {
        int index = nums.size()-2;
        while (index >=0 && nums[index] > nums[index+1])    index--;
        if (index < 0) {
            return false;
        }
        for (int i = nums.size()-1; i > index; i--) {
            if (nums[i] > nums[index]) {
                swap(nums[i], nums[index]);
                break;
            }
        }
        reverse(nums.begin()+index+1, nums.end());
        return true;
    }
    void swap(int& a, int& b) {
        int temp = a;
        a = b;
        b = temp;
    }
};