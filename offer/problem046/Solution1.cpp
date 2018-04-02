class Solution {
public:
    int GetMissingNumver(vector<int> data) {
        if (data.empty())   return -1;
        int left = 0, right = data.size() - 1;
        while (left <= right) {
            int mid = (left + right) / 2;
            if (data[mid] == mid) {
                left = mid + 1;
            } else if ((mid > 0 && data[mid - 1] == mid - 1) || mid == 0) {
                return mid;
            } else {
                right = mid - 1;
            }
        }
        return left;
    }
};