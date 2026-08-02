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
bool detect_cycle(Node* head){
    Node* slow = head;
    Node* fast = head;
    while(slow != NULL && fast != NULL && fast->next != NULL){
        slow = slow->next;
        fast = fast->next->next;
        if(slow == fast){
            return 1;
        }
    }
    return 0;
}
int main() {
int arr[] = {1, 2, 3, 4, 5};
Node* head = creation(arr, 5);
// unordered map appraoch
// Node* temp = head;
// unordered_map<Node*, bool>visited;
// while(temp != NULL){
//     if(visited[temp] == 1){
//         cout << "Cyclic Linked List" << endl;
//         return 0;
//     }
//     visited[temp] = 1;
// }
// cout << "Not a Cyclic Linked List" << endl;
if(detect_cycle(head)){
    cout << "Cyclic Linked List" << endl;
}
else{
    cout << "Not a Cyclic Linked List" << endl;
}
return 0;
}