#include <bits/stdc++.h>
using namespace std;
class Node {
    public:
    int data;
    Node* next;
    Node* prev;

    Node(int val){
        data = val;
        next = prev = NULL;
    }

};
Node* createList(Node* head, int arr[], int size){
    Node* curr = NULL;
    for(int i=0; i < size; i++){
        if(head == NULL){
        head = new Node(arr[i]);
        curr = head;
        }
        else {
            Node* temp = new Node(arr[i]);
            curr->next = temp;
            temp->prev = curr;
            curr= temp;
            
        }
        
    }
    return head;
}
Node* insertionAtStr(Node* head, int x){
    if(head == NULL){
        head = new Node(x);
        return head;
    }
    Node* temp = new Node(x);
    temp->next = head;
    head->prev = temp;
    head = temp;

    return head;

}
Node* insertionAtEnd(Node* head, int x){
    if(head == NULL){
        head = new Node(x);
        return head;
    }
    Node* newNode = new Node(x);
    Node* tail = head;
    while(tail->next != NULL){
        tail = tail->next;
    }
    tail->next = newNode;
    newNode->prev = tail;
    return head;

}
Node* insertionAtMid(Node* head, int x){
    if(head == NULL){
        head = new Node(x);
        return head;
    }
    Node* newNode = new Node(x);
    int cnt = 0;
    Node* tail = head;
    while(tail != NULL){
        cnt++;
        tail = tail->next;
    }
    cnt/=2;
    Node* temp = head;
    cnt--;
    while(cnt--){
        temp = temp->next;
    }
    Node* fut = temp->next;
    temp->next = newNode;
    newNode->prev = temp;
    newNode->next = fut;
    fut->prev = newNode;

return head;
}

int main(){
    int arr[]= {1, 2, 3, 4, 5};
    Node* head = NULL;
    head = createList(head, arr, 2);
    Node* temp = head;
    while(temp){
        cout << temp->data << " ";
        temp = temp->next;
    }
    //head = insertionAtStr(head, 7);
    //head = insertionAtEnd(head, 9);
    head = insertionAtMid(head, 8);
    cout << endl;
    temp = head;
    while(temp){
        cout << temp->data << " ";
        temp = temp->next;
    }

}