#include <iostream>
#include <vector>
using namespace std;
int recbinarySearch(vector<int> arr, int target, int left, int right){
     
    if(left <= right){
        int mid = left + (right - left)/2;
        if(target < arr[mid]){
            return recbinarySearch(arr, target, left, mid - 1);
        }
        else if(target > arr[mid]){
            return recbinarySearch(arr, target, mid + 1, right);
        }
        else{
            return mid;
        }
    }
    return -1;
}
int main(){
    int target;
    cin >> target;
    vector<int> arr = {1, 2, 3, 4, 5, 6, 7, 8, 9};

    cout <<  recbinarySearch(arr, target, 0, arr.size() - 1) << endl;
    return 0;
}