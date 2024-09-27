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

Node* removeDuplicate(Node* head){
    Node* prev = head;
    Node* temp = head->next;

    while (temp)
    {
        if(temp->data == prev->data){ //if duplicate node
            prev->next = temp->next;
            temp->next = NULL;
            delete temp;
            temp= prev->next;
        } else {
            prev = prev->next;
            temp= temp->next;
        }
    }

    return head;
}
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
int main(){
   int arr[5] = { 1,1,2,2,2};

   Node* head = arrToLL(arr, 5);
    print(head);

    head = removeDuplicate(head);

    print(head);




}