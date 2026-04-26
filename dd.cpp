#include <iostream>
#include <vector>
using namespace std;

// The comparison counter should be passed by reference, so we avoid using global variables.
void merge(vector<int> &arr, int s, int mid, int e, int &comparission) {
    vector<int> temp;
    int i = s;
    int j = mid + 1;

    while (i <= mid && j <= e) {
        comparission++;  // Increment comparison counter
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
    if (s >= e) return; // base case

    int mid = s + (e - s) / 2;
    mergeSort(arr, s, mid, comparission);    // Sort the left half
    mergeSort(arr, mid + 1, e, comparission); // Sort the right half
    merge(arr, s, mid, e, comparission);      // Merge the two halves
}

int main() {
    int comparission = 0;  // Local comparison counter
    vector<int> arr = {3, 9, 27, 38, 43, 82};

    mergeSort(arr, 0, arr.size() - 1, comparission);  // Pass reference of comparission

    for (int num : arr) {
        cout << num << " ";
    }
    cout << endl;
    cout << "Comparisons: " << comparission << endl;

    return 0;
}
