#include <iostream>
using namespace std;

void quickSort(int arr[], int left, int right) {
    int i = left, j = right;
    int tmp;
    int pivot = arr[(left + right) / 2];
    /* partition */
    while (i <= j) {
        while (arr[i] < pivot)
            i++;
        while (arr[j] > pivot)
            j--;
        if (i <= j) {
            swap(arr[i], arr[j]);
            i++;
            j--;
        }
    };
    /* recursion */
    if (left < j)
        quickSort(arr, left, j);
    if (i < right)
        quickSort(arr, i, right);
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