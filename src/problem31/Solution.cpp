class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        int len = nums.size();
        if(len < 2) return;
        int index = len-2;
        while (index >= 0 && nums[index] >= nums[index+1]) index--;
        if (index >= 0) {
            int j = len-1;
            while (j >= 0 && nums[j] <= nums[index])  j--;
            swap(nums[index],nums[j]);
        }
        reverse(nums.begin()+index+1, nums.end());

    }
    void swap(int& a, int& b) {
        int temp = b;
        b = a;
        a = temp;
    }
};