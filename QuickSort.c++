#include <iostream>
#include <vector>
using namespace std;

int partition(vector<int> &arr, int s, int e){
    int idx = s - 1;
    int pivot = arr[e];
     
     for(int j = s; j < e; j++){
        if(arr[j]  <=  pivot){
            idx++;
            swap(arr[idx], arr[j]);
        }
     }
     idx++;
     swap(arr[idx], arr[e]);
        return idx;
}

void quickSort(vector<int> &arr, int s, int e) {
    if (s < e) {
    int index  = partition(arr, s, e);
    quickSort(arr, s, index - 1);
    quickSort(arr, index + 1, e);
    }  
 }

 int main(){
    vector<int> arr = {5, 6, 3, 9, 1};
    int e = arr.size() -1;
    quickSort(arr, 0, e);
    for(int num : arr){
        cout << num << " ";
    }
    return 0;
    }
    
 
