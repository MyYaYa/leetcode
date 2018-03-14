#include <ctime>
#include <cstdlib>
#include <iostream>

using namespace std;

/**
 * how to select pivot
 **/
int SelectPivot(int arr[], int low, int high) {
    return arr[low];
}

int SelectPivotRandom(int arr[], int low, int high) {
    srand((unsigned int)time(NULL));
    int pivotPos = rand() % (high-low) + low;

    swap(arr[low], arr[pivotPos]);
    return arr[low];
}

int SelectPivotMedianOfThree(int arr[], int low, int high) {
    int mid = low + ((high - low) >> 1);

    if (arr[mid] > arr[high])
        swap(arr[mid], arr[high]);
    if (arr[low] > arr[high])
        swap(arr[low], arr[high]);
    if (arr[mid] > arr[low])
        swap(arr[mid], arr[low]);
    return arr[low];
}

/**
 * based on the pivot, partition the array.
 **/
int Partition(int arr[], int low, int high) {
    int pivot = SelectPivotMedianOfThree(arr, low, high);
    int i = low, j = high;
    while (i < j) {
        while (i < j && arr[j] >= pivot)    j--;
        arr[i] = arr[j];
        while (i < j && arr[i] < pivot)     i++;
        arr[j] = arr[i];
    } // assert i == j
    arr[i] = pivot;
    return i;
}

/**
 * optimize the recursive process -- tail call
 **/
void QuickSort(int arr[], int low, int high) {
    int pivotPos = -1;
    while (low < high) {
        pivotPos = Partition(arr, low, high);
        QuickSort(arr, low, pivotPos - 1);
        low = pivotPos + 1;
    }
}