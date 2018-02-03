#include <iostream>
using namespace std;

void swap(int &a, int &b) {
    int temp = a;
    a = b;
    b = temp;
}

void BubbleSort1(vector<int>& arr) {
    int length = arr.size();
    int i, j;
    for (i = length - 1; i > 0; i--) {
        for (j = 0; j < i; j++) {
            if (arr[j] > arr[j+1]) {
                swap(arr[j], arr[j+1]);
            }
        }
    }
}

void BubbleSort2(vector<int>& arr) {
    int length = arr.size();
    int i, j;
    for (i = 0; i < length - 1; i++) {
        for (j = i+1; j < length; j++) {
            if (arr[i] > arr[j]) {
                swap(arr[i], arr[j]);
            }
        }
    }
}

void BubbleSort3(vector<int>& arr) {
    int length = arr.size();
    int i,j;
    for(i=0; i<length-1; i++) {
        for(j=length-2; j>=i; j--)   //从右向左冒泡，较小的数向前端冒泡
            if(arr[j] > arr[j+1]) {
                swap(arr[j], arr[j+1]);
            }
    }
}

// optimized bubble sort
void BubbleSort4(vector<int>& arr) {
    int length = arr.size();
    int i, j;
    bool flag = true; //设置一个标记,数组中没有逆序就置flag为false，排序结束;
    //有逆序则置为true，做进一步操作。
    for(i = length-1; i > 0 && flag ; i--){
        flag = false;
        for(j = 0; j < i;j++){
            if(arr[j] > arr[j+1]) {
                swap(arr[j], arr[j+1]);
                flag = true;//存在逆序，所以置为true
            }
        }
    }
}

int main() {
    vector<int> a = {9,8,7,6,5,4,3,2,1};
    BubbleSort1(a);
    for (auto i : a) {
        cout << i << ' ';
    }
}