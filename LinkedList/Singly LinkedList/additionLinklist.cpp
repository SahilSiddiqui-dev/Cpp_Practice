#include <bits/stdc++.h>
using namespace std;
class Node {
    public:
    int data;
    Node* next;

    Node(int val){
        data = val;
        next = NULL;
    }
};
Node* creation(int arr[], int n, Node* head) {
    head = new Node(arr[0]);
    Node* temp = head;
    for(int i = 1; i < n; i++){
        temp -> next = new Node(arr[i]);
        temp = temp -> next;
    }
    temp->next = NULL;
    return head;
}
Node* reverse(Node* head){
    Node* curr = head;
    Node* prev = NULL;
    while(curr){
        Node* fut = curr->next;
        curr->next = prev;
        prev = curr;  
        curr = fut;
    }
    return prev;
}
Node* addNumberList(Node* head1, Node* head2){
    head1 = reverse(head1);
    head2 = reverse(head2);
    Node* it1 = head1;
    Node* it2 = head2;
    Node* head = new Node(0);
    Node* temp = head;
    int carry = 0;
    while(it1 && it2){
        int sum = it1->data + it2->data + carry;
        temp->next= new Node(sum%10);
        carry = sum/10;
        temp = temp->next;
        it1 = it1->next;
        it2 = it2->next;
    }
    while(it1){
        int sum = it1->data + carry;
        temp->next = new Node(sum%10);
        carry = sum/10;
        temp = temp->next;
        it1 = it1->next;
    }
    while(it2){
        int sum = it2->data + carry;
        temp->next = new Node(sum%10);
        carry = sum/10;
        temp = temp->next;
        it2 = it2->next;
    }
    while(carry){
        temp->next = new Node(carry%10);
        temp = temp->next;
        carry = carry/10;
    }
    temp->next = NULL;
        Node* result = reverse(head->next);
        return result;
}
int main(){
    int arr1[] = {0,0,0,2,3,7,1};
    int arr2[] = {0,0,3,1,1,2};
    Node* head1 = creation(arr1, 7, NULL);
    Node* head2  = creation(arr2,6,   NULL);
    head1 = addNumberList(head1, head2);
    
    Node* temp = head1;
    while(temp){
        cout << temp->data << endl;
        temp = temp->next;
    }
}