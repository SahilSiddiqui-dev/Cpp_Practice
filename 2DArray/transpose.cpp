#include <iostream>
using namespace std;
int main(){
    int m, n;
    cin >> n;
    cin >> m;
    cout << endl;
    int arr[50][50];
    int trans[50][50];
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            cin >> arr[i][j];
        }
    }
    cout << endl;
    cout << "The Matrix is: " << endl;
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            cout << arr[i][j] << " ";
        }
        cout << endl;
    }
    cout << endl;
    cout << "Transpose Matrix is : " << endl;
    for(int i = 0; i < m; i++){
        for(int j = 0; j < n; j++){
            trans[i][j] = arr[j][i];
        }
    }
    for(int i = 0; i < m; i++){
        for(int j = 0; j < n; j++){
            cout << trans[i][j] << " ";
        }
        cout << endl;
    }

    return 0;
}