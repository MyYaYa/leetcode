#include <iostream>
using namespace std;

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

int main() {
      int arr[10] = {1,2,3,4,5,6,7,8,9,10};
      cout << binarySearch(arr, 10, 0, 9);
}