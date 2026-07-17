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
Node* reverse(Node*curr, Node*prev){
    if(curr == NULL ){
        return prev;
    }
    Node* fut = curr->next;
    curr->next = prev;
   
    return reverse(fut, curr);
   
}
int main() {
    int arr[] = {1, 2, 3, 4, 5};
    Node* head = insertionVal(arr, 0, 5);
    Node* temp = head;
    cout << "Before Reverse : "; 
    while(temp != NULL){
        cout << temp->data << " ";
        temp = temp ->next;
    }
    cout << endl;
    cout << "After Reverse : ";
    Node* prev = NULL;
    head = reverse(head, prev);
    
    Node* temp2 = head;
    while(temp2 != NULL){
        cout << temp2->data << " ";
        temp2 = temp2 ->next;
    }


}