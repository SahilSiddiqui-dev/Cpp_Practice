#include <iostream>
using namespace std;
bool findout(int arr[100][100], int n, int m,  int key) {
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            if(arr[i][j] == key){
                return true;
            }
        }
    }
    return false;
}
int main(){
    int m, n;
    cin >> n;
    cin >> m;
    int key;
    cout << "key : ";
    cin >> key;
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
    if(findout(arr, n, m, key)){
        cout << "True";
    }
    else{
        cout << "False";
    }
    
    
    return 0;
}