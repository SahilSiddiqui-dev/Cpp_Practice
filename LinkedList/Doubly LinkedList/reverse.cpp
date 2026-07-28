#include <bits/stdc++.h>
using namespace std;
class Node{ 
    public:
    int data;
    Node* next;
    Node* prev;

    Node(int val){
        data = val;
        next = prev = NULL;
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
Node* reverse(Node* head){
    Node* back  = NULL;
    Node* curr = head;
    while(curr){
        back = curr->prev;
        curr->prev = curr->next;
        curr->next = back;
        curr = curr->prev;
        
    }
    return back->prev;
}
int main(){
    int arr[] = {1, 2, 3, 4, 5};
    Node* head = creation(arr, 0, 5, NULL);

    Node* temp = head;
    while(temp){
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;
    head = reverse(head);
    temp = head;
    while(temp){
        cout << temp->data << " ";
        temp = temp->next;
    }

}