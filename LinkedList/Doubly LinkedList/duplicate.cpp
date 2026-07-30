#include <bits/stdc++.h>
using namespace std;
class Node {
    public:
    int data;
    Node* next;
    Node* prev;

    Node(int val){
        data = val;
        next = NULL;
        prev = NULL;
    }
};
Node* creation(int arr[], int index, int size, Node* prev){
    if(index == size){
        return NULL;
    }
    Node* temp = new Node(arr[index]);
    temp->prev = prev;
    temp->next = creation(arr, index + 1, size, temp);
    return temp;
}
Node* duplicate(Node* head){
    Node* prev = head;
    Node* curr = prev->next;
    while(curr){
        Node* front = curr->next;
        if(prev->data == curr->data){
            prev->next = front;
            front->prev = prev;
            prev = curr;
            curr = front;
        }
        else {
            prev = curr;
            curr = curr->next;
        }
    }
    return head;
}
int main(){
    int arr[] = {1, 2, 2, 2, 2};
    Node* head = creation(arr, 0, 5, NULL);
    Node* temp = head;
    while(temp){
        cout << temp->data << " ";
        temp = temp -> next;
    }
    cout << endl;
    head = duplicate(head);
    temp = head;
    while(temp){
        cout << temp->data << " ";
        temp = temp -> next;
    }
}