class Solution {
public:
    void reOrderArray(vector<int> &array) {
        if (array.empty())  return;
        int length = array.size();
        int evenBegin = length;
        bool firstEven = false;
        for (int i = 0; i < length; i++) {
            if (!firstEven && array[i]%2 == 0) {
                evenBegin = i;
                firstEven = true;
            }
            if (evenBegin < i && array[i]%2 == 1) {
                int v = array[i];
                for (int j = i; j > evenBegin; j--) {
                    array[j] = array[j-1];
                }
                array[evenBegin] = v;
                evenBegin++;
            }
        }
    }
};