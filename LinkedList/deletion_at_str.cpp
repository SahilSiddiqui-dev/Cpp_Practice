#include <bits/stdc++.h>
using namespace std;

class Node {
    public:
    int data;
    Node* next;

    Node(int val ){
        data= val;
        next = NULL;
    }

};

Node* deleteAtHead(Node* head) {
    if(head == NULL){
        return NULL;
    }
    Node* temp = head;
    head = temp->next;
    delete temp;

    return head;
}

Node* insertionVal(int arr[], int index, int size){
    if(size == index){
        return NULL;
    }

    Node* temp = new Node(arr[index]);
   
    temp->next = insertionVal(arr, index + 1, size);
    
    return temp;

}
int main() {
    int arr[] = {1,2,3,4,5};
    int n = 5;
    Node* head = insertionVal(arr, 0, n);

    Node* temp = head;
    cout << "Before deletion" << " : ";
    while(temp != NULL){
        cout << temp->data << " ";
        temp = temp->next;
    }
    
    head = deleteAtHead(head);
    cout << endl;
    cout << "After deletion" << " : ";
    Node* a = head;
    while(a != NULL){
        cout << a->data << " ";
        a = a->next;
    }

}