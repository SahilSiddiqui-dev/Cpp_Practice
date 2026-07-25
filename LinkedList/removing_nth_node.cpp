#include <bits/stdc++.h>
using namespace std;
 
class  Node {
    public:
    int data;
    Node* next;

    Node(int val){
        data = val;
        next = NULL;
    }
};

Node* insertion(int arr[], int index, int size){
    if(index ==  size){
        return NULL;
    }
    Node* temp = new Node(arr[index]);
    temp->next = insertion(arr, index + 1, size);

    return temp;
}
Node* removeNthNode(Node* head, int k){
    Node* temp = head;
    int count = 0;
    while(temp != NULL){
        count++;
        temp = temp->next;
        
    }
    if(count == k){
        Node* temp1 = head;
        head = temp1 -> next;
        delete temp1;
        return head;
    }
    count = count - k;

    Node* prev = NULL;
    temp = head;
    while(count--){
        prev = temp;
        temp = temp->next;
    }
    prev->next = temp->next;
    delete temp;
    return head;
}
int  main(){
    int arr[] = {1, 2, 3, 4};
    Node* head = insertion(arr, 0, 4);
    Node* temp = head;
    while(temp != NULL){
        cout << temp->data << " ";
        temp = temp->next;
    }
    head = removeNthNode(head, 4);
    cout << endl;
    temp = head;
    while(temp != NULL){
        cout << temp->data << " ";
        temp = temp->next;
    }

}