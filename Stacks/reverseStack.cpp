// Online C++ compiler to run C++ program online
#include <iostream>
#include <stack>
using namespace std;

void print(stack<int>s){
    while(!s.empty()){
        cout<<s.top()<<" ";
        s.pop();
    }
}

void insertAtBottom(stack<int>&s, int value){
    if(s.empty()){
        s.push(value);
        return;
    }
    int topEle = s.top();
    s.pop();
    insertAtBottom(s,value);

    s.push(topEle);

}

void reverseStack(stack<int>&s){
    if(s.empty()){
        return;
    }

    int topEle = s.top();
    s.pop();

    reverseStack(s);

    //backtrack
    insertAtBottom(s, topEle);

}
int main()
{
    stack<int> s;
    s.push(10);
    s.push(20);
    s.push(30);
    s.push(40);
    s.push(50);

    print(s);
    reverseStack(s);
    cout<<endl;

    cout<<"After Reverse--> "<<endl;

    print(s);

    return 0;
}