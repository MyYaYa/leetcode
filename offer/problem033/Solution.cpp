class Solution {
public:
    int MoreThanHalfNum_Solution(vector<int> numbers) {
        if (numbers.empty())    return 0;
        int left = 0, right = numbers.size() - 1;
        int index = Partition(numbers, left, right);
        while (index != numbers.size() / 2) {
            if (index < numbers.size() / 2) {
                left = index + 1;
                index = Partition(numbers, left, right);
            } else {
                right = index - 1;
                index = Partition(numbers, left, right);
            }
        }
        int result = numbers[index];
        int times = 0;
        for (int k = 0; k < numbers.size(); k++) {
            if (numbers[k] == result)   times++;
        }
        return times > numbers.size()/2 ? result : 0;
    }

    // return pivot index
    int Partition(vector<int>& numbers, int left, int right) {
        int pivot = numbers[left];
        int i = left, j = right;
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