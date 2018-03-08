class Solution {
public:
    vector<int> GetLeastNumbers_Solution(vector<int> input, int k) {
        if (input.empty() || k == 0 || k > input.size())  return vector<int>();
        int left = 0, right = input.size() - 1;
        int index = Partition(input, left, right);
        while (index != (k-1)) {
            if (index < k - 1) {
                left = index + 1;
                index = Partition(input, left, right);
            } else {
                right = index - 1;
                index = Partition(input, left, right);
            }
        }
        vector<int> result;
        for (int i = 0; i < k; i++) {
            result.push_back(input[i]);
        }
        return result;
    }

    int Partition(vector<int>& numbers, int left, int right) {
        int i = left, j = right;
        int pivot = numbers[left];
        while (i < j) {
            while (i < j && numbers[j] >= pivot)    j--;
            numbers[i] = numbers[j];
            while (i < j && numbers[i] < pivot)     i++;
            numbers[j] = numbers[i];
        } // assert i == j
        numbers[i] = pivot;
        return i;
    }
};