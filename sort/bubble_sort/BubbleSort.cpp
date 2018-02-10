#include <iostream>
using namespace std;

void swap(int &a, int &b) {
    int temp = a;
    a = b;
    b = temp;
}

void bubbleSort(int arr[], int n) {
    bool swapped = true;
    int i, j;
    for (j = n-1; j >= 0; j--) {
        if (!swapped)   break;
        swapped = false;
        for (i = 0; i < j; i++) {
            if (arr[i] > arr[i+1]) {
                swap(arr[i], arr[i+1]);
                swapped = true;
            }
        }
    }
}

// cocktail sort
void cocktailSort(int arr[], int n) {
    bool swapped = true;
    int start=0, end=n-1;
    while (swapped) {
        swapped = false;
        // from left to right
        for (int i = start; i < end; i++) {
            if (arr[i] > arr[i+1]) {
                myswap(arr[i], arr[i+1]);
                swapped = true;
            }
        }
        end--;
        
        // from right to left
        for (int i = end; i > start; i--) {
            if (arr[i] < arr[i-1]) {
                myswap(arr[i], arr[i-1]);
                swapped = true;
            }
        }
        start++;
    }
}

int main() {
    int arr[10] = {9,8,7,5,6,3,4,0,1,2};
    bubbleSort(arr, 10);
    for (int i = 0; i < 10; i++)
        cout << arr[i] << " ";
}