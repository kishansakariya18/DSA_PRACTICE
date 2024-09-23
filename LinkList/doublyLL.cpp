#include <iostream>
using namespace std;

// create node
class Node
{
public:
    Node *prev;
    int data;
    Node *next;

    // constructor
    Node(int data)
    {
        this->data = data;
        this->prev = NULL;
        this->next = NULL;
    }
};
Node *insertAtHead(int val, Node *&head, Node *&tail)
{
    if (head == NULL && tail == NULL)
    {
        Node *newNode = new Node(val);
        head = newNode;
        tail = newNode;
    }
    else
    {
        Node *newNode = new Node(val);
        newNode->next = head;
        head->prev = newNode;
        head = newNode;
    }
    return head;
}

Node *insertAtTail(int val, Node *&head, Node *&tail)
{

    //*LL is empty
    if (head == NULL && tail == NULL)
    {
        // step 1: create new node
        Node *newNode = new Node(val);
        // update head
        head = newNode;
        // update tail
        tail = newNode;
    }
    else
    {
        //*LL is not empty
        // step:1 create new node
        Node *newNode = new Node(val);
        // step:2 connect tail to newNode
        tail->next = newNode;

        // step:3 connect newNode with tail node
        newNode->prev = tail;

        // step4: update tail to newNode
        tail = newNode;
    }
    return head;
}
int getLength(Node *head)
{
    int len = 0;

    Node *temp = head;
    while (temp != NULL)
    {
        len++;
        temp = temp->next;
    }
    return len;
}
Node *insertAtPosition(int val, int pos, Node *&head, Node *&tail)
{
    int len = getLength(head);
    cout << "len: " << len << endl;
    if (pos == 0)
    { // for first position
        insertAtHead(val, head, tail);
    }
    else if (pos == len + 1)
    { // for last position
        insertAtTail(val, head, tail);
    }
    else
    { // middle position

        Node *temp = head;
        // temp ko position - 2 aage badhana hai for add new node after temp
        for (int i = 0; i < pos - 2; i++)
        {
            temp = temp->next;
        }

        // create new node
        Node *newNode = new Node(val);

        // 1st method
        //  newNode->next = temp->next;
        //  newNode->prev = temp;
        //  temp->next->prev = newNode;
        //  temp->next = newNode;

        // 2nd easier --give name as forward for next pos node
        Node *forward = temp->next;
        temp->next = newNode;
        temp->prev = temp;
        newNode->next = forward;
        forward->prev = newNode;
    }

    return head;
}

bool searchInDoublyLL(Node *head, int target)
{
    Node *temp = head;

    while (temp != NULL)
    {
        if (temp->data == target)
        {
            return true;
        }
        temp = temp->next;
    }

    return false;
}

Node* deleteNode(int pos, Node*&head, Node*&tail){
    int len = getLength(head);
    if(head == NULL && tail == NULL){
        return NULL;
    } 
    else if(head == tail){ //single node
        Node* temp = head;
        head = NULL;
        tail = NULL;
        delete temp;
    }
    else if(pos == 1){
        Node* temp = head;
        head = temp->next;
        head->prev = NULL;
        temp->next = NULL;
        delete temp;
    }
    else if(pos == len){ // delete last node or tail node
        Node* temp = tail;
        tail = temp->prev;
        tail->next = NULL;
        temp->next = NULL;
        temp->prev = NULL;
        delete temp;
    }
    else{
        Node* temp = head;
        for (int i = 0; i < pos-2; i++)
        {
            temp = temp->next;
        }

        Node* current = temp->next;
        Node*forward = current->next;
        temp->next = forward;
        forward->prev = temp;
        current->prev = NULL;
        current->next = NULL;
        delete current;
        
    }
    return head;
}

void print(Node *&head)
{
    Node *temp = head;

    while (temp)
    {
        cout << temp->data << "->";
        temp = temp->next;
    }
    cout << "NULL" << endl;
}

void printReverse(Node *&tail)
{
    Node *temp = tail;

    while (temp)
    {
        cout << temp->data << "->";
        temp = temp->prev;
    }
    cout << "NULL" << endl;
}

int main()
{

    Node *head = NULL;
    Node *tail = NULL;
    head = insertAtHead(10, head, tail);
    head = insertAtHead(20, head, tail);
    print(head);
    // 20->10->NULL
    printReverse(tail);
    // 10->20->NULL
    head = insertAtTail(5, head, tail);
    print(head);
    // 20->10->5->NULL

    head = insertAtPosition(60, 2, head, tail);
    print(head);

    // search in LL
    int target = 60;
    bool isTargetExist = searchInDoublyLL(head, target);
    cout << "target is exist or not : " << isTargetExist << endl;


    //delete node
    deleteNode(4, head, tail);
    print(head);
}