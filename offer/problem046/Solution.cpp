class Solution {
public:
    int GetNumberOfK(vector<int> data ,int k) {
        if (data.empty())   return 0;
        int first = GetFirst(data, k);
        int last = GetLast(data, k);

        if (first >= 0 && last >= 0) {
            return (last - first + 1);
        } else {
            return 0;
        }
    }

    int GetFirst(vector<int> data, int k) {
        int left = 0, right = data.size() - 1;
        while (left <= right) {
            int mid = (left + right) / 2;
            if (data[mid] == k) {
                if ((mid > 0 && data[mid-1] != k) || mid == 0)
                    return mid;
                else
                    right = mid - 1;
            }
            else if (data[mid] > k)
                right = mid - 1;
            else
                left = mid + 1;
        }
        return left;
    }

    int GetLast(vector<int> data, int k) {
        int left = 0, right = data.size() - 1;
        while (left <= right) {
            int mid = (left + right) / 2;
            if (data[mid] == k) {
                if ((mid < data.size() - 1 && data[mid+1] != k) || mid == data.size() - 1)
                    return mid;
                else
                    left = mid + 1;
            }
            else if (data[mid] > k)
                right = mid - 1;
            else
                left = mid + 1;
        }
        return right;
    }
};