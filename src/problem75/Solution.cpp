class Solution {
public:
    void sortColors(vector<int>& nums) {
        int len = nums.size();
        int begin = 0, end = len-1;
        for (int i = 0; i <= end; i++){
            if (nums[i] == 0 && i != begin)
                swap(nums[i--], nums[begin++]);
            else if (nums[i] == 2 && i != end)
                swap(nums[i--], nums[end--]);
        }
    }

    void swap(int& a, int& b) {
        int temp = a;
        a = b;
        b = temp;
    }
};