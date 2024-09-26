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


Node* reverseList(Node* head){
    Node* prev = NULL;
    Node* curr = head;

    while (curr != NULL)
    {
        Node* forward = curr->next;
        curr->next = prev;
        prev = curr;
        curr = forward;
    }

    return prev;    
}
Node* findMiddle(Node*&head, Node*&prevOfMid){
    Node* slow = head;
    Node* fast = head;

    while (fast != NULL)
    {
        fast = fast->next;

        if(fast != NULL){
            fast= fast->next;
            prevOfMid=slow;
            slow = slow->next;
        }
    }

    return slow;
    
}

//normal approach 1. reverse and check
bool checkPalindrom(Node* head){


    Node* temp1 = head;
    Node* temp2 = reverseList(head);

    while (temp1 != NULL && temp2 != NULL)
    {
        if(temp1->data != temp2->data){
            return false;
        }
        temp1 = temp1->next;
        temp2 = temp2->next;
    }
    return true;
}

bool checkPalindrom2(Node* head){
    Node* temp = head;
    Node* prevOfMiddle = NULL;

    //find middle and prev of middle
    Node* middle = findMiddle(temp, prevOfMiddle); //O(N)


    //break LL from prevOfMid
    prevOfMiddle->next = NULL;

    Node* curr= middle;
    Node* newHead = reverseList(curr); //O(N)
    //compare
    Node* temp1 = head;
    Node* temp2 = newHead;
    while (temp1 != NULL) // O(N)
    {
        if(temp1->data != temp2->data){
            return false;
        }else{
        temp1 = temp1->next;
        temp2 = temp2->next;
        }

    }
    return true;

    //TC: O(N)
}
int main(){
   int arr[5] = { 1,2,3,2,1};

   Node* head = arrToLL(arr, 5);
    print(head);

    // int ans = checkPalindrom(head);
    int ans2 = checkPalindrom2(head);
    // cout<<"ll is palindrom res: "<<ans<<endl;
    cout<<"ll is palindrom res: "<<ans2<<endl;



}