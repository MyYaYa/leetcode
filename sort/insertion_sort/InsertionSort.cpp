#include <iostream>
#include <vector>
using namespace std;

// set sentinel -- temp.
void InsertionSort(vector<int>& arr) {
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

int main() {
    vector<int> arr = {1,3,-1,-6,7,6,5,4,3,2,1};
    InsertionSort(arr);
    for (auto i : arr) {
        cout << i << " ";
    }
}