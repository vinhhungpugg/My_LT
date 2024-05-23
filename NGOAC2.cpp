#include <iostream>
#include <stack>

#define ll long long

using namespace std;

ll test;

bool check(string s)
{
    ll n=s.size();
    stack<char> st;

    for (ll i=0;i<n;i++)
    {
        ll temp=s[i];

        if (temp=='(' || temp=='{' || temp=='[')
            st.push(temp);
        else
        {
            if (!st.empty() && temp=='}' && st.top()=='{')
                st.pop();
            else if (!st.empty() && temp==']' && st.top()=='[')
                st.pop();
            else if (!st.empty() && temp==')' && st.top()=='(')
                st.pop();
            else
                return false;
        }
    }
    if (!st.empty())
        return false;
    return true;
}


int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0),cout.tie(0);

    cin >> test;
    cin.ignore();

    while(test--)
    {
        string s;
        cin >> s;

        if (check(s))
            cout << "YES\n";
        else
            cout << "NO\n";
    }
}
