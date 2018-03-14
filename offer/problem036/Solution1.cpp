class Solution {
public:
    int FindGreatestSumOfSubArray(vector<int> array) {
        if (array.empty())  return 0;
        int len = array.size();
        int currentSum = 0;
        int greatestSum = INT_MIN;
        for (int i = 0; i < len; ++i) {
            if (currentSum <= 0)
                currentSum = array[i];
            else
                currentSum += array[i];
            greatestSum = max(currentSum, greatestSum);
        }
        return greatestSum;
    }
};