#include<iostream>
#include<map>
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

Node* arrToLL(int* arr, int size, Node*& tail){
    Node* head = new Node(arr[0]);
    Node* mover = head;

    for (int i = 1; i < size; i++)
    {
        Node* temp = new Node(arr[i]);
        mover->next = temp;
        tail = temp;
        mover = temp;
    }

    return head;
    
}

bool checkCyclicWithMap(Node* head){
    Node* temp = head;
    map<Node* , bool>mpp;


    while (temp != NULL)
    {

        if(mpp[temp] == true){
            return true;
        } else {
            mpp[temp] = true;
        }

        temp = temp->next;
        
    }

    return false;
    
}

// using two pointer approach ( slow and fast)
bool checkCyclicWithTwoPointer(Node* head){

    //both pointer assign to head
    Node* slow = head;
    Node* fast = head;

    while (fast != NULL)
    {
        fast = fast->next;

        if(fast != NULL){
            fast = fast->next;
            slow = slow->next;
        }

        if(fast == slow){
            return true;
        }
    }

    return false;
    
    
}


void print(Node* head){
    Node* temp = head;
    while(temp){
        cout<<temp->data<<"->";
        temp = temp->next;
    } cout<<"NULL"<<endl;
}

int main(){
    int arr[6] = {1,2,3,4,5, 6};
    Node* tail = NULL;

    Node* head = arrToLL(arr, 6, tail);
    // tail->next = head->next->next;

    cout<<"ans: "<<checkCyclicWithMap(head)<<endl;
    cout<<"ans2: "<<checkCyclicWithTwoPointer(head)<<endl;
}