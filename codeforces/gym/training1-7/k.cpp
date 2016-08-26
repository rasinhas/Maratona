#include <iostream>
#include <cstdio>
#include <string>
#include <stack>
#include <algorithm>

using namespace std;

int main()
{
    int n, k;
    string s;
    stack <char> st;
    cin >> n >> k;
    cin >> s;
    for(int i=0;i<n;i++)
    {
        if(st.empty()) st.push(s[i]);
        else
        {
            while(!st.empty() && st.top() < s[i] && k)
            {
                st.pop();
                k--;
            }
            st.push(s[i]);
        }
    }
    s = "";
    while(!st.empty())
    {
        s += st.top();
        st.pop();
    }
    reverse(s.begin(),s.end());
    cout << s << endl;
    return 0;
}
