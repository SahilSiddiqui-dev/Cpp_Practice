#include <bits/stdc++.h>
using namespace std;
void merge(vector<int> &arr, int low, int mid, int high, int&comparision){
    int i = low;
    int k = 0;
    int j = mid + 1;
    vector<int> temp(high - low + 1);
    while(i <= mid && j <= high){
        comparision++;
        if(arr[i] < arr[j]){
            temp[k++] = arr[i++];
        }
        else{
            temp[k++] = arr[j++];
        }
    }
    while(i<= mid){
        temp[k++] = arr[i++];
    }
    while(j <= high){
        temp[k++] = arr[j++];
    }
    for(int p = 0; p < temp.size(); p++){
        arr[p + low]  = temp[p];
    }
}
void mergeSort(vector<int> &arr, int low, int high, int&calls, int&comparision){
    calls++;
    if(low < high){
        int mid = low + (high - low)/2;
        mergeSort(arr, low, mid, calls, comparision);
        mergeSort(arr, mid + 1, high, calls, comparision);
        merge(arr, low, mid, high, comparision);

    }
}
int main(){
int n;
cin >> n;
vector<int> arr(n);

cout << endl;
for(int i = 0; i < n; i++){
    cin >> arr[i];
}
int calls = 0;
int comparision = 0;
mergeSort(arr, 0 , n -1, calls, comparision);
for(int i : arr){
    cout << i << " ";
}
cout << calls << endl;
cout << calls << endl;
return 0;
}
