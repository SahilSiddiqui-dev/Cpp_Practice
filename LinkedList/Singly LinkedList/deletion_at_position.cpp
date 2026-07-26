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

Node* insertionVal(int arr[], int index, int size){
    if(size == index){
        return NULL;
    }

    Node* temp = new Node(arr[index]);
   
    temp->next = insertionVal(arr, index + 1, size);
    
    return temp;

}

Node* deletionNode(int position, Node* head) {
    if(head == NULL){
        return nullptr;
    }
    else if (position == 1 && head->next != NULL){ 
        Node* temp = head;
        head = head-> next;
        delete temp;
    }
    else if(position == 1 && head->next == NULL){
        delete head;
        head = nullptr;
    }
    else {
        Node* temp = head;
        Node* prev = NULL;
        position--;
        while(position--){
           prev = temp;
           temp = temp->next;
        }
        prev->next = temp->next;
        delete temp;
    }
     return head;
}
int main(){
    int arr[] = {1,2,3,5,6};
    int n = 5;
    int position = 3;
    Node* head = insertionVal(arr, 0, n);

    Node* temp = head;
    cout << "Before deletion" << " : ";
    while(temp != NULL){
        cout << temp->data << " ";
        temp = temp->next;
    }
    
    head = deletionNode(5, head);
    cout << endl;
    cout << "After deletion" << " : ";
    Node* a = head;
    while(a != NULL){
        cout << a->data << " ";
        a = a->next;
    }
}
