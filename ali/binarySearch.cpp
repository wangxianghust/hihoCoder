// 一个先递增再递减的序列，寻找一个特定的元素，返回下标或-1, 序列无重复元素

// x: 待查询元素, n: arr长度
int findPeakIndex(int arr[], int left, int right, int n){
    int mid = (right-left)/2 + left;
    if(mid-1 >= 0 && mid+1 <= n-1){
        int mid_left = arr[mid-1];
        int mid_right = arr[mid+1];
        int mid_ele = arr[mid];
        if(mid_left < mid_ele && mid_ele < mid_right){
            return findPeakIndex(arr, mid+1, right, n);
        } else if(mid_left > mid_ele && mid_ele > mid_right){
            return findPeakIndex(arr, left, mid-1, n);
        } else {
            return mid; //find the peak index;
        }
    } else {
        //单调序列
        return -1;
    }
}

int binarySearch(int arr[], int left, int right, int x, bool direction){
    int mid = (right - left)/2 + left;
    if(left <= right){
        int mid_ele = arr[mid];
        if(x > mid_ele){
            // true denotes increaseing seq;
            return direction ? binarySearch(arr, mid+1, right, x, direction) : binarySearch(arr, left, mid-1, x, direction);
        } else if(x < mid_ele){
            return direction ? binarySearch(arr, left, mid-1, x, direction) : binarySearch(arr, mid+1, right, x, direction);
        } else {
            return mid;
        }
    }
    return -1;
}

int findIndex(int arr[], int x, int n){
    //handle n equals 0 or 1;
    if(n == 0) return -1;
    if(n == 1) {
        if(x == arr[0])return 0;
        else return -1;
    }
    int peak = findPeakIndex(arr, 0, n-1, n);
    int ret(-1);
    if(peak == -1){
        bool direction = (arr[0] < arr[1]);
        ret = binarySearch(arr, 0, n-1, x, direction);
    } else {
        int tmp1 = binarySearch(arr, 0, peak, x, true);
        int tmp2 = binarySearch(arr, peak+1, n-1, x, false);
        if(tmp1 != -1) {
            ret = tmp1;
        } else {
            ret = tmp2;
        }
    }
    return ret;
}

 titan ，neo4j

#include <iostream>

using std::cout;
using std::endl;

int main(){
    cout << "test" << endl;
    return 0; //ok
}
