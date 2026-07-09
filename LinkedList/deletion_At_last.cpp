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

Node* deletionAtLast(Node* head) {
     if(head != NULL){
        if(head->next == NULL){
            delete head;
            head = NULL;
        }
        else {
            Node* last = head;
            Node* prev =  NULL;
            while(last->next != NULL){
                prev = last;
                last =  last->next;
            }
            delete last;
            prev->next = NULL;
        }
    }
    return head;
}
int main(){
    int arr[] = {1};
    int n = 1;
    Node* head = insertionVal(arr, 0, n);

    Node* temp = head;
    cout << "Before deletion" << " : ";
    while(temp != NULL){
        cout << temp->data << " ";
        temp = temp->next;
    }
    
    head = deletionAtLast(head);
    cout << endl;
    cout << "After deletion" << " : ";
    Node* a = head;
    while(a != NULL){
        cout << a->data << " ";
        a = a->next;
    }
}
