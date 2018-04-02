class Solution {
public:
    int InversePairs(vector<int> data) {
        if (data.empty())   return 0;
        vector<int> copy(data);
        long long count = mergeSort(data, copy, 0, data.size()-1);
        return count % 1000000007;
    }
    long long mergeSort(vector<int>& data, vector<int>& copy, int begin, int end) {
        // process the end-recursive condition
        if (begin == end) {
            copy[begin] = data[begin];
            return 0;
        }
        // recursively
        int mid = (begin + end) / 2;
        long long leftCount = mergeSort(copy, data, begin, mid);
        long long rightCount = mergeSort(copy, data, mid + 1, end);

        // compute the count of inverse pairs.
        int firstEnd = mid;
        int secondEnd = end;
        long long count = 0;
        int copyIndex = end;
        while (firstEnd >= begin && secondEnd >= mid + 1) {
            if (data[firstEnd] > data[secondEnd]) {
                count += (secondEnd - mid);
                copy[copyIndex--] = data[firstEnd--];
            } else {
                copy[copyIndex--] = data[secondEnd--];
            }
        }
        while (firstEnd >= begin) {
            copy[copyIndex--] = data[firstEnd--];
        }
        while (secondEnd >= mid + 1) {
            copy[copyIndex--] = data[secondEnd--];
        }
        return (leftCount + rightCount + count);
    }
};