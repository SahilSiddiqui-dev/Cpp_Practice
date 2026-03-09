#include <iostream>
#include <vector>
using namespace std;

int binarySearch(vector<int> arr, int target){
    int low = 0; 
    int high = arr.size() - 1;
    int mid;
    while(low < high){
        mid = low + (high - low)/ 2;
        if(target == arr[mid]){
            return mid;
        }
        else if ( target < arr[mid]){
            high = mid - 1;
        }
        else {
            low = mid + 1;
        }
    }
    return -1;
}
int main(){
    int target;
    vector<int> arr = {1,2,3,4,5,6,7,8,9,10};
    cout << "Enter the target number: ";
    cin >> target;
    int result = binarySearch(arr, target);
    cout << "Element found at index: " << result << endl;
}