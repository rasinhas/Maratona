#include <iostream>
#include <cstdio>
#include <string>

using namespace std;

int g[111111][12];
int c;
int estados;
int fail;
void init() 
{
    for(int j=0;j<10;j++) g[0][j] = -1;
    g[0][10] = g[0][11] = 0;
    estados = 1;
}
void add(string s) 
{
    int e = 0;
    int i = 0;
    int next = s[i]-'0';
    while(s[i] != '\0')
    {
        next = (s[i] - '0');
        if (g[e][next] == -1) {
            g[e][next] = estados;
            for(int j=0;j<10;j++) g[estados][j] = -1;
            g[estados][10] = g[estados][11] = 0;
            estados++;
        }
        e = g[e][next];
        g[e][11]++;
        if(g[e][11] > 1 && g[e][10] > 0) fail = 1;
        i++;
    }
    g[e][10]++;
    if(g[e][11] > 1) fail = 1;
}

int main()
{
    int n, t;
    string s;
    cin >> t;
    while(t--)
    {
        fail = 0;
        cin >> n;
        init();
        for(int i=0;i<n;i++)
        {
            cin >> s;
            add(s);
        }
        cout << (fail ? "NO" : "YES") << endl;
    }
    return 0;
}
