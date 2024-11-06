#include <iostream>
#include <queue>
#include <stack>
using namespace std;

void reverseInKGroup(queue<int> &q, int &k, int size)
{
    stack<int> st;

    if (k <= size)
    {
        for (int i = 0; i < k; i++)
        {
            int front = q.front();
            q.pop();
            st.push(front);
        }

        for (int i = 0; i < k; i++)
        {
            int top = st.top();

            st.pop();

            q.push(top);
        }

        reverseInKGroup(q, k, size - k);
    }
    else
    {
        for (int i = 0; i < size; i++)
        {
            int front = q.front();
            q.pop();
            q.push(front);
        }
    }
}

void print(queue<int> q)
{
    while (!q.empty())
    {
        int front = q.front();
        q.pop();
        cout << front << " ";
    }
    cout << endl;
}
int main()
{
    queue<int> q;
    q.push(10);
    q.push(20);
    q.push(30);
    q.push(40);
    q.push(50);
    q.push(60);
    q.push(70);
    q.push(80);

    int k = 3;

    int size = q.size();
    cout<<"Before reverse"<<endl;
    print(q);
    reverseInKGroup(q, k, size);
    cout<<"After reverse"<<endl;
    print(q);

    return 0;
}