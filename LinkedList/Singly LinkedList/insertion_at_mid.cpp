#include <bits/stdc++.h>
using namespace std;
class Node {
    public:
    int data;
    Node *next;

    Node(int val){
        data= val;
        next = NULL;
    }
};

Node *insertionzVal(int arr[], int size, int index, Node  *prev){

    if(size == index){
       return prev;
    }

    Node *temp;
    temp = new Node(arr[index]);
    temp->next = prev;

    return insertionzVal(arr,size, index + 1, temp);
}

int main(){
    Node* head = NULL;
    int x = 3;
    int val = 10;
    int arr[] = {1, 2, 3, 4, 5};
    head = insertionzVal(arr, 5, 0, head);
    Node* temp1 = head;

    Node *temp2 = new Node(val);
    x--;
    while(x--){
        temp1 = temp1->next;
    }
    temp2->next = temp1->next;
    temp1->next = temp2;
    
    Node* temp = head;
    while(temp != NULL){
        cout << temp->data << endl;
        temp = temp->next;
    }
}