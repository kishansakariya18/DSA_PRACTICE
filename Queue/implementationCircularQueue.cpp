#include<iostream>
using namespace std;

class CircularQueue{
    public:
    int n;
    int front;
    int rear;
    int *arr;

    //initialize props
    CircularQueue(int n){
        this->n = n;
        arr = new int[n];
        front = -1;
        rear = -1;
    }

    void push(int val){
        // 4 cases : Overflow, first Element, circular nature, normal flow
        if((front == 0 && rear == n-1) || (rear == front - 1)){
            cout<<"Overflow"<<endl;
        }
        else if(front == -1 && rear == -1){
            rear++;
            front++;
            arr[front] = val;
        } 
        else if(rear == n-1 && front != 0) //circular case
        {
            rear = 0;
            arr[rear] = val;
        }
        else { // normal case
            rear++;
            arr[rear] =  val;
        }
    }

    void pop(){
        // 4 case : empty queue -> underflow, 1 element, circular, normal
        if(front == -1 && rear == -1){
            cout<<"Underflow"<<endl;
        } else if(front == rear){
            arr[rear] = -1;
            front = -1;
            rear = -1;
        } else if(front == n-1){
            //circular nature
            arr[front] = -1;
            front = 0;
        } else {
            arr[front] = -1;
            front++;
        }
    }
    int getSize(int n){
        if(front == -1 && rear == -1){
            return 0;
        } else {
            return abs(rear - front) + 1;
        }
    }

    bool isEmpty(){
        if(front == -1 && rear == -1){
            return true;
        } else return false;
    }

    void print(){
        for(int i =0 ; i< n; i++){
            cout<<arr[i]<<" ";
        } cout<<endl;
    }

    int getSize(){
        if(front == -1 && rear == -1){
            return 0;
        } 
        else if(rear > front){
            return rear - front + 1;
        } else if(rear == front){
            return 1;
        } else {
            return n - front + rear + 1;
        }
    }
};
int main(){
    CircularQueue q(5);

    q.push(1);
    q.print();
    q.push(2);
    q.print();
    q.pop();
    q.print();
    q.push(3);
    q.print();
    q.push(4);
    q.print();
    q.push(5);
    q.print();
    cout<<q.getSize()<<endl;
    q.push(6);
    q.print();
    cout<<q.getSize()<<endl;

}