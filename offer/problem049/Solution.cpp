class Solution {
public:
    vector<int> FindNumbersWithSum(vector<int> array,int sum) {
        vector<int> result;
        if (array.empty())  return result;
        int left = 0, right = array.size() - 1;
        while (left < right) {
            if (array[left] + array[right] == sum) {
                result = {array[left], array[right]};
                break;
            } else if (array[left] + array[right] < sum) {
                ++left;
            } else {
                --right;
            }
        }
        return result;
    }
};