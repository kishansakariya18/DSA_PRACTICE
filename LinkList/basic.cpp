#include<iostream>
using namespace std;


//create node
class Node {
    public:
    int data;
    Node* next;

    //constructor
    Node(int data){
        this->data = data;
        this->next = NULL;
    }
};

Node* insertAtHead(int val,Node*& head, Node*&tail){
    if(head == NULL && tail ==NULL){
        Node* newNode = new Node(val);
        head = newNode;
        tail = newNode;
    } else{
        Node* newNode = new Node(val);
        newNode->next = head;
        head = newNode;
    }
    return head;
}

Node* insertAtTail(int val, Node*& head, Node*& tail){
      if(head == NULL && tail ==NULL){
        Node* newNode = new Node(val);
        head = newNode;
        tail = newNode;
    } else{
        Node* newNode = new Node(val);
        tail->next = newNode;
        tail = newNode;
    }
    return head;
}

int getLength(Node*& head){
    int len = 0;
    Node*temp = head;
    while (temp)
    {
        len++;
        temp = temp->next;
    }

    return len;
    
}

Node* insertAtPosition(int val, int pos, Node*&head, Node*&tail){
    int len = getLength(head);

    if(pos == 1){
        insertAtHead(val,head, tail);
    } else if(pos == len+1){

        Node* newNode = new Node(val);

        tail->next = newNode;
        tail = newNode;
        newNode->next = NULL;
    } else
    {
        Node* temp = head;
        for(int i= 0 ; i< pos-2; i++){
            temp = temp->next;
        }

        Node* newNode = new Node(val);
        newNode->next = temp->next;
        temp->next = newNode;
    }
    
}

bool searchNode(int target, Node*& head){
    Node* temp = head;

    while (temp)
    {
        if(temp->data == target){
            return true;
        }
        temp = temp->next;
    }
    return false;
    
}

Node* deleteNode(int pos, Node*& head, Node*& tail){
    Node* temp = head;

    if(pos == 1){
        head = temp->next;
        temp->next = NULL;
        delete temp;
    } else {
    for(int i = 0 ; i< pos-2; i++){
        temp = temp = temp->next;
    }

    Node* prev =temp;
    Node* curr = temp->next;
    Node* forward = curr->next;

    prev->next = forward;
    curr->next = NULL;
    delete curr;
    }
    return head;
}


void print(Node*& head){
    Node* temp = head;

    while (temp)
    {
        cout<<temp->data<<"->";
        temp = temp->next;
    }cout<<"NULL"<<endl;
}


int main(){
    Node* newNode = new Node(30);
    Node* head = newNode;
    Node* tail = newNode;

    head = insertAtHead(20, head, tail);
    print(head);
    head = insertAtTail(40, head, tail);
    head = insertAtTail(50, head, tail);
    print(head);    
    head = insertAtHead(10, head, tail);
    print(head);
    int len = getLength(head);

    cout<<"Length of LL: "<<len<<endl;

    insertAtPosition(25, 3,head, tail);

    print(head);

    bool isExist = searchNode(30, head);

    cout<<"30 isExist: "<<isExist<<endl;

    cout<<"before delete: "<<endl;
    print(head);

    deleteNode(6, head, tail);
    cout<<"After Delete: "<<endl;

    print(head);








}