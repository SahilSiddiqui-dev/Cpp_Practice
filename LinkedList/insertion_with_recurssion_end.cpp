#include <bits/stdc++.h>
using namespace std;

class Node {
    public:
    int data;
    Node *next;

    Node(int value) {
        data = value;
        next = NULL;
    }
};

Node * insertionVal(int arr[], int index, int size){
    if(size == index) {
        return NULL;
    }
    Node *temp;
    temp = new Node(arr[index]);
    
    temp->next = insertionVal(arr, index + 1, size);

    return temp;

}
int main(){
    Node* head = NULL;
    int arr[] = {1, 2, 3, 4, 5};
    head = insertionVal(arr, 0, 5);
    Node* temp = head;
    while(temp != NULL){
        cout << temp->data << endl;
        temp = temp->next;
    }
}