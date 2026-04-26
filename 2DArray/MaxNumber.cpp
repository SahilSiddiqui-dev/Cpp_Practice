#include <iostream>
#include <limits.h>
using namespace std;
void Max_Min(int arr[100][100], int n, int m) {
    int maxi = INT_MIN;
    int mini = INT_MAX;
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            if(maxi < arr[i][j]){
                maxi = arr[i][j];
            }
            if(mini > arr[i][j]){
                mini = arr[i][j];
            }
            }
        }
        cout << "This is the Maximum number: " << maxi << endl;
        cout << "This is the Minimum number: " << mini << endl; 
}
int main(){
    int m, n;
    cin >> n;
    cin >> m;
    cout << endl;
    int arr[100][100];
    //THIS IS HOW WE TAKE INPUT FOR 2D ARRAY [ MATRIX ]
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            cin >> arr[i][j];
        }
    }
    cout<< endl;
    //THIS IS HOW WE PRINT 2D ARRAY [ MATRIX ]
    cout << "The matrix is : " << endl ;
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            cout << arr[i][j] << " ";
            
        }
        cout<<endl;
    }
    cout << endl;
    Max_Min(arr, n, m);

    
    
    
    return 0;
}