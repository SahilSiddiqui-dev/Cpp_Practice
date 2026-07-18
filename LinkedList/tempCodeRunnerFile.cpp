 Node* head = insertionVal(arr, 0, 5);
    Node* temp = head;
    cout << "Before Reverse : "; 
    while(temp != NULL){
        cout << temp->data << " ";
        temp = temp ->next;
    }
    cout << endl;
    cout << "After Reverse : ";