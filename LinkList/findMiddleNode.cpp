//find total length and divide by 2
#include<iostream>
using namespace std;
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
int getLength(Node* head){
    int len = 0;

    Node* temp = head;
    while (temp)
    {
        len++;
        temp= temp->next;
    }
    return len;
}

int normalApproach(Node* head){
        int len = getLength(head);

    int mid = len/2;

    Node* temp = head;

    for(int i = 0; i < mid; i++){
        temp = temp->next;
    }
    return temp->data;
}

int twoPointerApproach(Node*&head){
    Node* fast = head;
    Node* slow = head;


    while(fast != NULL){
        //1. fast ko 1 step chalaye 
        fast = fast->next;

        //2.check fast is null or not
        if(fast != NULL){
            //3.if fast not null then again move 1 step
            fast = fast->next;
            //4. slow move one step
            slow = slow->next;
        }

    }

    return slow->data;
}

int main(){
   int arr[5] = { 1,2,3,4,5};

   Node* head = arrToLL(arr, 5);
    print(head);



    cout<<"mid data: "<<normalApproach(head)<<endl;
    cout<<"mid data: "<<twoPointerApproach(head)<<endl;



}