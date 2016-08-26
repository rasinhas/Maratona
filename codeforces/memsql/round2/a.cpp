#include <iostream>
#include <cstdio>
#include <string>

using namespace std;

int l[33];
int c[33];

int main()
{
    int n, m;
    string s;
    cin >> s;
    cin >> n;
    for(int i=0;i<s.size();i++) l[s[i]-'a']++;
    for(int i=0;i<26;i++)
    {
        if(l[i]) 
        {
            c[i]++;
            n--;
        }
    }
    if(n < 0) cout << -1 << endl;
    else
    {
        while(n)
        {
            m = 0;
            for(int i=0;i<26;i++)
            {
                if(l[i]*c[m] > l[m]*c[i]) m = i;
            }
            c[m]++;
            n--;
        }
        m = 0;
        int cnt=0, k=0;
        for(int i=0;i<26;i++) if(l[i]*c[m] > l[m]*c[i]) m = i;
        while(cnt < l[m])
        {
            cnt += c[m];
            k++;
        }
        cout << k << endl;
        for(int i=0;i<26;i++)
        {
            for(int j=0;j<c[i];j++) cout << (char)('a'+i);
        }
        cout << endl;
    }
    return 0;
}
