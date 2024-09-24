#include <iostream>
using namespace std;

class Node {
public:
    int data;
    Node* next;

    Node(int data){
        this->data = data;
        this->next = NULL;
    }
};
void print(Node* head){
    Node* temp = head;

    while (temp != NULL)
    {
        cout<<temp->data<<"->";
        temp = temp->next;
    } cout<<"NULL"<<endl;
    
}
Node* arrToLL(int* arr, int size){
    Node* head = new Node(arr[0]);
    Node* mover = head;
    for(int i = 1; i< size; i++){
        Node* temp = new Node(arr[i]);
        mover->next = temp;
        mover = temp;
    }

    return head;
}
Node* reverseListWithRecursion(Node*&prev , Node*& curr){

    if(curr == NULL){
        return prev;
    }

    Node* forward = curr->next;
    curr->next = prev;
    prev = curr;
    curr = forward;

    return reverseListWithRecursion(prev, curr);
}

Node* reverseListWithIterator(Node*&prev, Node*&curr){

    while (curr != NULL)
    {
        Node* forward = curr->next;
        curr->next = prev;
        prev = curr;
        curr = forward;
    }
    return prev;
    
}
int main(){
   int arr[5] = { 1,2,3,4,5};

   Node* head = arrToLL(arr, 5);
    print(head);


    //recursive method
    Node* prev = NULL;
    Node* curr = head;

    Node* newHead = reverseListWithRecursion(prev, curr);
    print(newHead);

    curr = newHead;
    prev = NULL;
    newHead = reverseListWithIterator(prev, curr);
    print(newHead);



}