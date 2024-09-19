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


int main(){
    Node* newNode = new Node(30);

    cout<<newNode->data<<" ";

}