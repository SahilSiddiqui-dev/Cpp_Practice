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
Node* middleNode(Node* head){
    Node* slow = head;
    Node* fast = head;
    while(fast != NULL && fast->next != NULL){
        slow = slow->next;
        fast  = fast -> next -> next;
    }
    return slow;
}

int main() {
    int arr[] = {1, 2, 3, 4, 5, 6};
    Node* head = insertionVal(arr, 0, 6);
    
    Node* temp2 = head;
    while(temp2 != NULL){
        cout << temp2->data << " ";
        temp2 = temp2 ->next;
    }
    Node* ans = middleNode(head);
    cout << endl;
    cout << ans->data;

}