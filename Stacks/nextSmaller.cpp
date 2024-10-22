#include <iostream>
#include <vector>
#include <stack>
using namespace std;

vector<int> nextSmallerNumber(vector<int> &v)
{
    vector<int> ans;
    stack<int> st;
    st.push(-1);
    int n = v.size();
    for (int i = n - 1; i >= 0; i--)
    {

        while (st.top() > v[i])
        {
            st.pop();
        }

        ans.push_back(st.top());
        st.push(v[i]);
    }

    return ans;
}

int main()
{
    vector<int> arr;
    arr.push_back(2);
    arr.push_back(1);
    arr.push_back(4);
    arr.push_back(3);

    vector<int> ans = nextSmallerNumber(arr);

    reverse(ans.begin(), ans.end());

    for (int &it : ans)
    {
        cout << it << " ";
    }
    cout<<endl;
}