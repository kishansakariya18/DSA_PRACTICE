#include <iostream>
#include <stack>
using namespace std;
bool isValid(string str)
{
    stack<char> st;

    for (int i = 0; i < str.length(); i++)
    {
        int ch = str[i];

        if (ch == '(' || ch == '[' || ch == '{')
        {
            st.push(ch);
        }
        else if (!st.empty() && ch == '}' && st.top() == '{')
        {
            st.pop();
        }
        else if (!st.empty() && ch == ']' && st.top() == '[')
        {
            st.pop();
        }
        else if ( !st.empty() && ch == ')' && st.top() == '(')
        {
            st.pop();
        }
        else
        {
            return false;
        }
    }
    return true;
}
int main()
{
    string str = "([(}])";

        bool ans = isValid(str);

    cout << "ans: " << ans << endl;
}