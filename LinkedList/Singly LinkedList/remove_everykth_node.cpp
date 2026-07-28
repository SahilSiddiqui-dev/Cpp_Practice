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
    Node* curr = head;
    Node* prev = NULL;
    int cnt = 1;
    if(cnt == k){
        return NULL;
    }
    while(curr != NULL){
        if(cnt != k){
            cnt++;
            prev = curr;
            curr = curr->next;
        }
        else {
            prev->next = curr->next;
            Node* temp = curr;
            delete temp;
            curr = prev->next;
            cnt = 1;
        }

    }
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
    head = removeNthNode(head, 2);
    cout << endl;
    temp = head;
    while(temp != NULL){
        cout << temp->data << " ";
        temp = temp->next;
    }

}