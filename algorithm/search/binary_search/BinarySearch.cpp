#include <iostream>
using namespace std;

// iterating
int binarySearch(int arr[], int value, int left, int right) {
      while (left <= right) {
            int middle = (left + right) / 2;
            if (arr[middle] == value)
                  return middle;
            else if (arr[middle] > value)
                  right = middle - 1;
            else
                  left = middle + 1;
      }
      return -1;
}

// recursively
int binarySearch(int arr[], int low, int high, int v) {
    if (low > high) return -1;
    else {
        int mid = (low + high) / 2;
        if (arr[mid] == v)  return mid;
        else if (arr[mid] < v)  return binarySearch(arr, mid+1, high, v);
        else    return binarySearch(arr, low, mid-1, v);
    }
}

int main() {
      int arr[10] = {1,2,3,4,5,6,7,8,9,10};
      cout << binarySearch(arr, 10, 0, 9);
}