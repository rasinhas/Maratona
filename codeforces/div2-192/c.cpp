#include <iostream>
#include <cstdio>
#include <string>
#include <cstring>
#include <algorithm>

using namespace std;

typedef long long ll;

int main()
{
    int n;
    int c;
    int l=0;
    string s[111];
    cin >> n;
    for(int i=0;i<n;i++) cin >> s[i];
    for(int i=0;i<n;i++)
    {
        c = 0;
        for(int j=0;j<n;j++)
        {
            if(s[i][j] == '.') c++;
        }
        if(c > 0) l++;
    }
    if(l == n)
    {
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<n;j++)
            {
                if(s[i][j] == '.')
                {
                    cout << i+1 << " " << j+1 << endl;
                    break;
                }
            }
        }
        return 0;
    }
    else 
    {
        l = 0;
        for(int i=0;i<n;i++)
        {
            c = 0;
            for(int j=0;j<n;j++)
            {
                if(s[j][i] == '.') c++;
            }
            if(c > 0) l++;
        }
    }
    if(l < n) cout << -1 << endl;
    else
    {
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<n;j++)
            {
                if(s[j][i] == '.')
                {
                    cout << j+1 << " " << i+1 << endl;
                    break;
                }
            }
        }
    }
    return 0;
}
