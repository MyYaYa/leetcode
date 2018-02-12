class Solution {
public:
    int minNumberInRotateArray(vector<int> rotateArray) {
        int length = rotateArray.size();
        int left = 0, right = length-1;
        // only when it is rotated, continue
        while (left < right-1 && rotateArray[left] >= rotateArray[right]) {
            int mid = (left + right) / 2;
            if (rotateArray[mid] >= rotateArray[left])
                left = mid;
            else if (rotateArray[mid] <= rotateArray[right])
                right = mid;
        }
        return min(rotateArray[left], rotateArray[right]);
    }
};