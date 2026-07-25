
#include <bits/stdc++.h>
using namespace std;

class Node {
    public:
    int data;
    Node *next;

    Node(int value) {
        data = value;
        next = NULL;
    }
};

Node * insertionVal(int arr[], int index, int size){
   if(index == size){
    return NULL;
   }
   Node* temp = new Node(arr[index]);
   temp->next = insertionVal(arr, index + 1, size);
   return temp;

}
Node* reverse(Node* head) {
    Node* prev = NULL;
    Node* curr = head;
    while (curr != NULL) {
        Node* fut = curr->next;
        curr->next = prev;
        prev = curr;
        curr = fut;
    }
    return prev;
}
bool isPalindrome(Node* head) {
        // vector<int>arr;
        // Node* temp = head;
        // while(temp != NULL){
        //     arr.push_back(temp->data);
        //     temp = temp->next;
        // }
        // int size = arr.size();
        // int j = size - 1;
        // for(int i = 0; i < size/2; i++){
        //     if(arr[i] != arr[j]){
        //         return false;
        //     }
        //     j--;
            
        // }
        // return true;
        if(head->next == NULL){
            return true;
        }
        int cnt = 0;
        Node* temp = head;
        while(temp != NULL){
            cnt++;
            temp = temp->next;
        }
        cnt = cnt/2;
        temp = head;
        Node* prev = NULL;
        while(cnt--){
            prev = temp;
            temp = temp->next;

        }
        prev->next = NULL;
        Node* head2 = reverse(temp);
        Node* head1 = head;
        while(head1 != NULL){
            if(head1->data == head2->data){
            head1 = head1->next;
            head2 = head2 ->next;
            }
            else {
                return false;
            }
        }
        return true;
}
int main(){
    Node* head = NULL;
    int arr[] = {1, 1, 2, 1};
    head = insertionVal(arr, 0, 4);
    Node* temp = head;
    while(temp != NULL){
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;
    cout << isPalindrome(head);
}