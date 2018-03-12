//
// Created by 薄一丁 on 2018/3/12.
//

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
int binarySearch1(int arr[], int v, int left, int right, int v) {
    if (left > right)
        return -1;
    else {
        int mid = (left + right) / 2;
        if (arr[mid] == v)  return mid;
        else if (arr[mid] < v)
            return binarySearch(arr, v, mid+1, right);
        else    return binarySearch(arr, v, left, mid-1);
    }
}

// find the last less or equal than the value
int binarySearch(vector<int> nums, int v) {
    int left = 0, right = nums.size()-1;
    while (left <= right) {
        int mid = (left + right) / 2;
        if (nums[mid] > v)  right = mid - 1;
        else left = mid + 1;
    }
    return right;
}

// find the last less than the value
int binarySearch(vector<int> nums, int v) {
    int left = 0, right = nums.size()-1;
    while (left <= right) {
        int mid = (left + right) / 2;
        if (nums[mid] >= v)  right = mid - 1;
        else left = mid + 1;
    }
    return right;
}

// find the first greater or equal than the value
int binarySearch(vector<int> nums, int v) {
    int left = 0, right = nums.size()-1;
    while (left <= right) {
        int mid = (left + right) / 2;
        if (nums[mid] < v)  left = mid + 1;
        else right = mid - 1;
    }
    return left;
}

// find the first greater than the value
int binarySearch(vector<int> nums, int v) {
    int left = 0, right = nums.size()-1;
    while (left <= right) {
        int mid = (left + right) / 2;
        if (nums[mid] <= v)  left = mid + 1;
        else right = mid - 1;
    }
    return left;
}


int main() {
    int arr[10] = {1,2,3,4,5,6,7,8,9,10};
    cout << binarySearch(arr, 10, 0, 9);
}