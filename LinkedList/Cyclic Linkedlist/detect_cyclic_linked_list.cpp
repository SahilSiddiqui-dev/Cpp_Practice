#include <bits/stdc++.h>
using namespace std;
struct Node {
    int data;
    Node* next;

    Node(int val){
        data = val;
        next = NULL;
    }
};
Node* creation(int arr[], int n){
    int i = 0;
    Node* head = new Node(arr[i]);
    Node* curr = head;

    for(int i = 0; i < n; i++){
        Node* temp = new Node(arr[i]);
        curr->next = temp;
        curr = curr->next;
    }

    curr->next = head;
    
   return head;
}
int main() {
int arr[] = {1, 2, 3, 4, 5};
Node* head = creation(arr, 5);
Node* temp = head;

unordered_map<Node*, bool>visited;

while(temp != NULL){
    if(visited[temp] == 1){
        cout << "Cyclic Linked List" << endl;
        return 0;
    }
    visited[temp] = 1;
}
cout << "Not a Cyclic Linked List" << endl;
return 0;
}