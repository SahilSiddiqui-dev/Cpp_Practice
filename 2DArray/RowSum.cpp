#include <iostream>
using namespace std;
int main(){
    int m, n;
    cin >> n;
    cin >> m;
    cout << endl;
    int arr[n][m];
//THIS IS HOW WE TAKE INPUT FOR 2D ARRAY [ MATRIX ]
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            cin >> arr[i][j];
        }
    }
    cout<< endl;
//THIS IS HOW WE PRINT 2D ARRAY [ MATRIX ]
cout << "The matrix is : " << endl;
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            cout << arr[i][j] << " ";
            
        }
        cout<<endl;
    }
     cout<<endl;
    cout << "Row Sum " << endl;
    for(int i = 0; i < n; i++){
        int sum = 0;
        for(int j = 0; j < m; j++){
            sum  = sum + arr[i][j];
            
        }
        cout << sum << " ";
        cout<<endl;
    }
    cout << endl;
    cout << "coln Sum " << endl;
    for(int i = 0; i < n; i++){
        int sum = 0;
        for(int j = 0; j < m; j++){
            sum  = sum + arr[j][i];
            
        }
        cout << sum << " ";
        cout<<endl;
    }
    return 0;
}