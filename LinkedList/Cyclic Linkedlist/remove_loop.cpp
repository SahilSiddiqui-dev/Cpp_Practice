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
Node* removeLoop(Node* head){
    Node* slow = head;
    Node* fast = head;
    int cnt= 1;
    while(fast != NULL && fast->next != NULL){
        slow = slow ->next;
        fast = fast->next->next;
        
        if(slow == fast){
            break;
        }
    }
    slow = slow ->next;
    while(slow != fast){
            cnt++;
            slow = slow -> next;
        }
    slow = head;
    fast = head;
    while(cnt--){
        fast = fast->next;
    }
    while(slow != fast){
        slow = slow->next;
        fast = fast->next;
    }
    slow = fast->next;
    while(slow->next != fast){
        slow = slow->next;
    }
    slow->next = NULL;
    return head;
}

int main() {
int arr[] = {1, 2, 3, 4, 5};
Node* head = creation(arr, 5);
//head = removeLoop(head);
if(detect_cycle(head)){
    cout << "Cyclic Linked List" << endl;
}
else{
    cout << "Not a Cyclic Linked List" << endl;
}

return 0;
}