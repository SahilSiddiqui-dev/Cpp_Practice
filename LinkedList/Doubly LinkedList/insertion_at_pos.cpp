#include <bits/stdc++.h>
using namespace std;
class Node {
    public:
    int data;
    Node* next;
    Node* prev;

    Node(int val){
        data =  val;
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
            curr->next = temp;
            temp->prev = curr;
            curr =temp;
        }
    }
    return head;
}
Node* insertionAtPos(Node* head, int pos, int x){
    if(head == NULL){
        return new Node(x);
    }
    if(pos == 0){
        Node* temp = new Node(x);
        temp->next = head;
        head->prev = temp;
        head = temp;
        return head;
    }
    else {
        Node* temp = head;
        while(--pos){
            temp = temp->next;
        }
        if(temp->next == NULL){
            Node* newNode = new Node(x);
            temp->next = newNode;
            newNode->prev = temp;
        }
        else {
            Node* last = temp->next;
            Node* newNode = new Node(x);
            temp->next = newNode;
            newNode->prev = temp;
            newNode->next = last;
            last->prev = newNode;
        }

    }

    return head;
}

int main(){
int arr[] = {1, 3, 4, 5, 6, 7};
Node* head = creation(arr, 1, NULL);
Node* temp = head;
while(temp){
    cout << temp->data << " ";
    temp = temp->next;
}
cout << endl;
cout << "After Insertion" << " : ";
head = insertionAtPos(head,2, 8);
temp = head;
while(temp){
    cout << temp->data << " ";
    temp = temp->next;
}
cout << endl;
}