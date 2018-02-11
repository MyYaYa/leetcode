#include <iostream>
using namespace std;

void swap(int &a, int &b) {
    int temp = a;
    a = b;
    b = temp;
}

/**
 * (1) "Sifting down" using swap
 */
void insertionSort(int arr[], int length) {
      int i, j;
      for (i = 1; i < length; i++) {
            j = i;
            while (j > 0 && arr[j - 1] > arr[j]) {
                swap(arr[j], arr[j-1]);
                j--;
            }
      }
}

/**
 * (2) Shifting instead of swapping
 * set sentinel -- temp
 */
void insertionSort(vector<int>& arr) {
    int length = arr.size();
    int i, j;
    for (i = 1; i < length; i++) {
        int temp = arr[i];
        for (j = i-1; j >= 0 && arr[j] > temp; j--) {
            arr[j+1] = arr[j];
        }
        arr[j+1] = temp;
    }
}

/**
 * (3) Using binary search
 */
// binary search, find the position to insert.
int bs(int arr[], int v, int start, int end) {
    while (start < end) {
        int mid = (start + end) / 2;
        if (arr[mid] == v) {
            return mid;
        } else if (arr[mid] < v) {
            start = mid+1;
        } else {
            end = mid-1;
        }
    }
    return arr[start] < v ? start+1 : start;
}
// insertion sort using binary search
void insertionSort(int arr[], int length) {
    int i, j;
    for (i = 1; i < length; i++) {
        int ins_pos = bs(arr,arr[i], 0, i-1);
        int temp = arr[i];
        for (j = i; j > ins_pos; j--) {
            arr[j] = arr[j-1];
        }
        arr[j] = temp;
    }
}


int main() {
    int arr[10] = {1,3,-1,-6,7,6,5,4,3,2};
    insertionSort(arr, 10);
    for (int i = 0; i < 10; i++)
        cout << arr[i] << " ";
}