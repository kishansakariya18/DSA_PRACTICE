// Online C++ compiler to run C++ program online
#include <iostream>
#include <stack>
using namespace std;

void findMiddle(stack<int> &s, int count, int &ans)
{
    if (count == 0)
    {
        ans = s.top();
        return;
    }

    int topEle = s.top();
    s.pop();
    count--;
    findMiddle(s, count, ans);

    // backtrack
    s.push(topEle);
}
int main()
{
    stack<int> s;
    s.push(10);
    s.push(20);
    s.push(30);
    s.push(40);
    s.push(50);
    int count = s.size() / 2;
    int ans = -1;
    findMiddle(s, count, ans);

    cout << "ans: " << ans << endl;

    return 0;
}