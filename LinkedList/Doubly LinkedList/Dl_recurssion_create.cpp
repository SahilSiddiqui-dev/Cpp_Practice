#include <bits/stdc++.h>
using namespace std;
class Node {
    public:
    int data;
    Node* next;
    Node* prev;

    Node(int val){
        data = val;
        next = prev = NULL;
    }

};
Node* insertionAtStr(int arr[], int size, int index, Node* last){

    if(index == size){
        return  last;
    }
    Node* temp = new Node(arr[index]);

    if(last != NULL){
        temp->next = last;
        last->prev = temp;
    }
    return insertionAtStr(arr, size, index+1, temp);
}

Node* insertionAtEnd(int arr[], int size, int index, Node*tail){
    if(index == size){
        return NULL;
    }
    Node* temp = new Node(arr[index]);
    temp -> prev = tail;
    temp->next = insertionAtEnd(arr, size, index + 1, temp);

return temp;
}
int main(){
    int arr[]= {1, 2, 3, 4, 5};
    Node* head = NULL;
    head = insertionAtStr(arr, 5, 0, head);
    // head = insertionAtEnd(arr, 5, 0, NULL);
    Node* temp = head;
    while(temp){
        cout << temp->data << " ";
        temp = temp->next;
    }

}