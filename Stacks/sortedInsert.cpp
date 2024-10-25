#include<iostream>
#include<stack>
using namespace std;

void print(stack<int>s){
    while(!s.empty()){
        cout<<s.top()<<" ";
        s.pop();
    }
}
void sortedInsert(stack<int>&s, int val){
    if( !s.empty()  && s.top() <= val){
        s.push(val);
        return ;
    }

    if(s.empty()){
        s.push(val);
        return;
    }

    int topEle = s.top();
    s.pop();

    sortedInsert(s, val);

    //backtrack
    s.push(topEle);
}
int main(){

        stack<int> s;
    s.push(10);
    s.push(20);
    s.push(30);
    s.push(40);
    s.push(50);

    print(s);
    sortedInsert(s, 23);
    cout<<endl;
    print(s);

}