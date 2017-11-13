class Solution {
public:
    bool canJump(vector<int>& nums) {
        if (nums.empty())
            return false;
        if (nums.size()==1)
            return true;
        int reach = 0;
        int i=0;
        for (i = 0; i <= reach && i < nums.size(); i++) {
            reach = max(i+nums[i], reach);
        }
        return i==nums.size();
    }
};