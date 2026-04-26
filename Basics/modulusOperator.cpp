#include<iostream>
using namespace std;
int main(){
    int a, b;
    a =10;
    b = 3;
    cout << "Modulus of a nd b: " << a % b << endl;
    cout << "Modulus of b and a: " << b % a << endl; // b%a = b, since b < a
    cout << "Modulus of a and -b: "<< a % -b << endl; // a%(-b) = a%(-b)
    cout << "Modulus of -a and b: "<< -a % b << endl; //(-a)%b = -[a%b]

}   