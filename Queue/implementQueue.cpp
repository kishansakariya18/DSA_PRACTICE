#include <iostream>
using namespace std;
class Queue
{
private:
    int *arr;
    int n;
    int front; // front ele
    int rear;  //  back ele


    public:

    Queue(int size)
    {
        arr = new int[size];
        n = size;
        front = -1;
        rear = -1;
    }

    void push(int val)
    {
        if (rear == n - 1)
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

    void pop()
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

    int getFront()
    {
        if (front == -1)
        {
            cout << "Queue is Empty" << " ";
        }
        else
        {
            return arr[front];
        }
    }
    int getRear()
    {
        if (rear == -1)
        {
            cout << "Queue is Empty" << " ";
        }
        else
        {
            return arr[rear];
        }
    }

    int getSize()
    {
        return rear - front + 1;
    }

    bool isEmpty()
    {
        if (front == -1 && rear == -1)
        {
            return true;
        }
        else
        {
            return false;
        }
    }
};
int main()
{


    Queue q(5);
    q.push(1);
    q.push(2);
    q.push(3);
    q.push(4);
    q.push(4);
    q.push(4);


    cout<<q.getSize()<<endl;
    cout<<q.getFront()<<endl;
    cout<<q.isEmpty()<<endl;
    cout<<q.getRear()<<endl;
}