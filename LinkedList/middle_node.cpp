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
    int count = 0;
    Node* temp = head;
    while(temp != NULL){
            count++;
            temp = temp->next;
        }
    
    count /= 2;
    Node*temp1 = head;
    while(count--){
        temp1 = temp1->next;
    }

    return temp1;
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