#include <iostrem>
using namespace std;

void merge(int arr[], int l, int mid, int r) {
    int len = r - l + 1;
    // declair a new array, length is r-l+1
    int temp[len];
    int i = l, j = mid + 1;
    int k = 0;
    // merge two part, save into temp
    while (i <= mid && j <= r) {
        if (arr[i] < arr[j]) {
            temp[k] = arr[i];
            i++;
            k++;
        } else {
            temp[k] = arr[j];
            j++;
            k++;
        }
    }
    while (i <= mid) {
        temp[k] = arr[i];
        i++;
        k++;
    }
    while (j <= r) {
        temp[k] = arr[j];
        j++;
        k++;
    }
    // assign temp to original arr
    for (int p = l; p <= r; p++) {
        arr[p] = temp[p - l];
    }
}

void mergeSort(int arr[], int l, int r) {
    // only when l < r, need to sort
    if (l < r) {
        int mid = (l + r) / 2;
        // divide
        mergeSort(arr, l, mid);
        mergeSort(arr, mid + 1, r);
        // merge
        merge(arr, l, mid, r);
    }
}

int main() {
//    int arr[10] = {9,8,7,5,6,3,4,0,1,2};
//    int arr[10] = {9,8,7,6,5,4,3,2,1,0};
//    int arr[10] = {0,1,2,3,4,5,6,7,8,9};
    int arr[10] = {1,3,-1,-6,7,6,5,4,3,2};
//    int arr[10] = {0,2,4,6,8,10,12,14,16,18};
    mergeSort(arr, 0, 9);
    for (int i = 0; i < 10; i++)
        cout << arr[i] << " ";
}