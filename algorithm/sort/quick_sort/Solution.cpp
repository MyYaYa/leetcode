#include <iostream>
using namespace std;

/**
 * partition method 1
 * from two boundaries to middle, swap the lesser and the larger.
 */
void quickSort(int arr[], int left, int right) {
    int i = left, j = right;
    int pivot = arr[left];
    /* partition */
    while (i < j) {
        while (i < j && arr[j] >= pivot)
            j--;
        arr[i] = arr[j];
        while (i < j && arr[i] < pivot)
            i++;
        arr[j] = arr[i];
    }; // assert i == j
    arr[i] = pivot;
    /* recursion */
    if (i > left + 1)
        quickSort(arr, left, i-1);
    if (i < right - 1)
        quickSort(arr, i+1, right);
}

/**
 * partition method 2:
 * from left to right, swap lessers to the left.
 */
int partition(int arr[], int left, int right) {
    swap(arr[(left+right)/2], arr[right]);
    int small = left;
    for (int i = left; i < right; i++) {
        if (arr[i] < arr[right]) {
            if (i != small) {
                swap(arr[i], arr[small]);
            }
            small++;
        }
    }
    swap(arr[small], arr[right]);
    return small;
}
void quickSort1(int arr[], int left, int right) {
    if (left >= right) return;
    int mid = partition(arr, left, right);
    if (mid > left) quickSort(arr, left, mid-1);
    if (mid < right)    quickSort(arr, mid+1, right);
}

int main() {
//    int arr[10] = {9,8,7,5,6,3,4,0,1,2};
//    int arr[10] = {9,8,7,6,5,4,3,2,1,0};
//    int arr[10] = {0,1,2,3,4,5,6,7,8,9};
    int arr[10] = {1,3,-1,-6,7,6,5,4,3,2};
//    int arr[10] = {0,2,4,6,8,10,12,14,16,18};
//    cout << bs(arr, 20, 0, 9);
    quickSort(arr, 0, 9);
    for (int i = 0; i < 10; i++)
        cout << arr[i] << " ";
}