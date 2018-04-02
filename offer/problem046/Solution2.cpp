class Solution {
public:
    int GetNumberSameAsIndex(vector<int> data) {
        if (data.empty())   return -1;
        int left = 0, right = data.size() - 1;
        while (left <= right) {
            int mid = (left + right) / 2;
            if (data[mid] == mid) {
                return mid;
            } else if (data[mid] > mid) {
                right = mid - 1;
            } else {
                left = mid + 1;
            }
        }
        return -1;
    }
};