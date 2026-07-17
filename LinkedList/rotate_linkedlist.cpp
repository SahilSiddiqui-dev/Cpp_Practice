#include <bits/stdc++.h>
using namespace std;
class Node {
    public:
    int data;
    Node* next;

    Node(int val) {
        data = val;
        next = nullptr;
    }
};
Node *insertionVal(int arr[], int index, int size){
    if(index == size){
        return NULL;
    }
    Node* temp;
    temp = new Node(arr[index]);

    temp->next = insertionVal(arr, index + 1, size);

    return temp;

}
Node* rotate(Node* head, int k){

    if(head == NULL || head ->next == NULL || k == 0){
        return head;
    }

    Node* original = head;
    Node*temp = head;
    int count = 0;
    while(temp != NULL){
        count++;
        temp = temp->next;
    }
    k = k % count;
    if(k == 0){
        return head;
    }
    temp = head;
    while(k--){
        temp = temp->next;
    }
    
    Node* newHead = temp->next;
    temp->next = NULL;
    Node* temp1 = newHead;
    while(temp1->next != NULL){
        temp1 = temp1->next;
    }
    temp1->next = original;
    return newHead;
}

int main() {
    int arr[] = {1, 2, 3, 4, 5, 6};
    Node* head = insertionVal(arr, 0, 6);

    Node* temp2 = head;
    while(temp2 != NULL){
        cout << temp2->data << " ";
        temp2 = temp2 ->next;
    }
    head = rotate(head, 4);
cout << endl;
    Node* temp = head;
    while(temp != NULL){
        cout << temp->data << " ";
        temp = temp->next;
    }
    

}