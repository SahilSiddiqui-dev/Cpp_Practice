#include <bits/stdc++.h>
using namespace std;
class Node {
    public:
    int data;
    Node *next;

    Node(int val){
        data= val;
        next = NULL;
    }
};

Node *insertionzVal(int arr[], int size, int index, Node  *prev){
    if(index == size){
        return prev;
    }
    Node* temp = new Node(arr[index]);
    temp->next = prev;
    return insertionzVal(arr, size, index + 1, temp);
}

int main(){
    Node* head = NULL;
    int arr[] = {1, 2, 3, 4, 5};
    head = insertionzVal(arr, 5, 0, head);

    Node* temp = head;
    while(temp != NULL){
        cout << temp->data << endl;
        temp = temp->next;
    }
}