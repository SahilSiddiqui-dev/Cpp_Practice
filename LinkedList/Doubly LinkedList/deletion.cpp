#include<bits/stdc++.h>
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
Node* creation(int arr[], int size, Node* head){
    Node* curr = NULL;
    for(int i = 0; i < size; i++){
        if(head == NULL){
            head = new Node(arr[i]);
            curr = head;
        }
        else {
            Node* temp = new Node(arr[i]);
            curr -> next = temp;
            temp->prev = curr;
            curr = temp;
        }
    }
    return head;
}
Node* deletionAtStr(Node* head){
    if(head->next == NULL){
        delete head;
        return NULL;
    }
    Node* temp = head;
    head = head->next;
    head->prev = NULL;
    delete temp;
    return head;
}
Node* deletionAtEnd(Node* head){
    if(head -> next == NULL){
        delete head;
        return NULL;
    }
    Node* temp = head;
    Node* last = NULL; 
    while(temp->next){
        last = temp;
        temp = temp->next;
    }
    last->next = NULL;
    delete temp;
    return head;
    
}
Node* deletionAtMid(Node* head){
    if(head == NULL || head -> next == NULL){
        delete head;
        return NULL;
    }
    Node* temp = head;
    int cnt = 0;
    while(temp){
        cnt++;
        temp = temp->next;
    }
    
    cnt/=2;
    temp = head;
    while(cnt--){
        temp= temp->next;
    }
    Node* back = temp->prev;
    Node* front = temp->next;
    if(back) back->next = front;
    else head = front;
    if(front) front->prev = back;

    delete temp;
    return head;

}
Node* deleteAtPos(Node* head, int pos){
    if(head ==  NULL|| pos == 0){
        delete head;
        return NULL;
    }
    Node* temp = head;
    while(--pos){
        temp = temp->next;
    }
    Node* back = temp->prev;
    Node* front = temp->next;
    if(back) back->next = front;
    else head = front;
    if(front) front->prev = back;
    delete temp;
    return head;
}
int main(){
int arr[] = {1, 2, 3, 4, 5, 6};
Node* head = creation(arr, 6, NULL);
cout << "beforee : ";
Node* temp = head;
while(temp){
    cout << temp->data << " ";
    temp = temp->next;
}
head = deleteAtPos(head, 3);
cout << endl << "after :" << " ";
temp = head;
while(temp){
    cout << temp->data << " ";
    temp = temp->next;
}

}