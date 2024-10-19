// Online C++ compiler to run C++ program online
#include <iostream>
#include <stack>
using namespace std;

bool checkSorted(stack<int> &s, int element1)
{
    if (s.empty())
    {
        return true;
    }

    int element2 = s.top();
    s.pop();

    if (element2 < element1)
    {
        bool aagekaans = checkSorted(s, element2);
        // backtrack
        s.push(element2);
        return aagekaans;
    } else {
        return false;
    }
}
int main()
{
    stack<int> s;
    s.push(10);
    s.push(40);
    s.push(30);
    s.push(40);
    s.push(50);
    bool ans = checkSorted(s, INT_MAX);
    cout<<ans<<endl;

    return 0;
}