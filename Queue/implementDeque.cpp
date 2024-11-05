#include <iostream>
using namespace std;

class Dequeue
{
private:
    int n;
    int *arr;
    int front;
    int rear;

public:
    Dequeue(int size)
    {
        n = size;
        arr = new int[size];
        front = -1;
        rear = -1;
    }

    void pushFront(int val)
    {
        if (front == 0)
        {
            cout << "overflow" << endl;
        }
        else if (front == -1 && rear == -1)
        {
            front++;
            rear++;
            arr[front] = val;
        }
        else
        {
            front--;
            arr[front] = val;
        }
    }

    void pushBack(int val)
    {
        if (rear == n)
        {
            cout << "overflow" << endl;
        }
        else if (front == -1 && rear == -1)
        {
            rear++;
            front++;
            arr[rear] = val;
        }
        else
        { // normal case
            rear++;
            arr[rear] = val;
        }
    }

    void popFront()
    {
        if (n == 0)
        {
            cout << "underflow" << endl;
        }
        else if (rear == front)
        { // only ele;
            rear = -1;
            front = -1;
        }
        else
        {                    // normal
            arr[front] = -1; // optional
            front++;
        }
    }
    void popBack()
    {

        if (rear == -1 && front == -1)
        {
            cout << "underflow" << endl;
        }
        else if (front == rear)
        {
            // only one element left
            arr[front] = -1;
            front = -1;
            rear = -1;
        }
        else
        {
            arr[rear] = -1;
            rear--;
        }
    }

    int getSize()
    {
        return rear - front + 1;
    }
    void print()
    {
        for(int i = 0; i< n; i++){
            cout<<arr[i]<<" ";
        } cout<<endl;
    }
};

int main()
{

    Dequeue q(5);
    q.pushFront(10);
    q.print();
    q.pushBack(12);
    q.print();
    q.pushFront(18);
    q.print();
    q.popFront();
    q.print();
    q.popBack();
    q.print();
    q.pushBack(12);
    q.print();
    cout<<q.getSize()<<" ";

}