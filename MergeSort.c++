#include <iostream>
#include <vector>
using namespace std;
int comparission = 0;
void merge(vector<int> &arr, int s, int mid, int e, int &comparission) {
    vector<int> temp;
    int i = s;
    int j = mid + 1;
    
    while (i <= mid && j <= e) {
        comparission++;
        if (arr[i] <= arr[j]) {
            temp.push_back(arr[i]);
            i++;
        } else {
            temp.push_back(arr[j]);
            j++;
        }
    }

    while (i <= mid) {
        temp.push_back(arr[i]);
        i++;
    }

    while (j <= e) {
        temp.push_back(arr[j]);
        j++;
    }

    for (int idx = 0; idx < temp.size(); idx++) {
        arr[s + idx] = temp[idx];
    }
}

void mergeSort(vector<int> &arr, int s, int e, int &comparission) {
    if (s >= e) return; //  base case added

    int mid = s + (e - s) / 2;
    mergeSort(arr, s, mid, comparission);
    mergeSort(arr, mid + 1, e, comparission);
    merge(arr, s, mid, e);
}

int main() {
    int comparission = 0;
    vector<int> arr = {3, 9, 27, 38, 43, 82};
    mergeSort(arr, 0, arr.size() - 1, comparission);
    
    for (int num : arr) {
        cout << num << " ";
    }
    cout << endl;
    cout<< comparission; 
    

    return 0;
}
