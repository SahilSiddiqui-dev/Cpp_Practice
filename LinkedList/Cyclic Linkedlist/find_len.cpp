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
int findLen(Node* head){
    Node* slow = head;
    Node* fast = head;
    int cnt = 0;
    while(slow != NULL && fast != NULL && fast->next != NULL){
        slow = slow->next;
        fast = fast->next->next;
        Node* temp = NULL;
        

        if(slow == fast){
            temp = slow;
            slow = slow->next;
            while(slow != temp){
                cnt++;
                slow = slow->next;
            }
            return cnt;
        }
    }
    return 0;
}
int main() {
int arr[] = {1, 2, 3, 4, 5};
Node* head = creation(arr, 4);

if(detect_cycle(head)){
    cout << "Cyclic Linked List" << endl;
}
else{
    cout << "Not a Cyclic Linked List" << endl;
}
cout << endl;
int x =  findLen(head);
cout << x;
return 0;
}