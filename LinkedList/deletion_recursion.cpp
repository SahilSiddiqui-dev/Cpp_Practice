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

Node* deletionNode(int position, Node* curr) {
    if(position == 1){
        Node* temp = curr->next;
        delete curr;
        return temp;
    }
    curr->next = deletionNode(position - 1, curr -> next);
    return curr;
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
    
    head = deletionNode(4, head);
    cout << endl;
    cout << "After deletion" << " : ";
    Node* a = head;
    while(a != NULL){
        cout << a->data << " ";
        a = a->next;
    }
}
