#include <iostream>
#include <cstdio>
#include <string>
#include <cstring>
using namespace std;

string s;
string T[33] = {".-", "-...", "-.-.", "-..", 
              ".", "..-.", "--.", "....",
              "..", ".---", "-.-", ".-..",
              "--", "-.", "---", ".--.",
              "--.-", ".-.", "...", "-",
              "..-", "...-", ".--", "-..-",
              "-.--", "--.."};

long long dp[11111];
long long g[1111111][3];
int estados;
void init() 
{
    for(int j=0;j<3;j++) g[0][j] = -1;
    g[0][2] = 0;
    estados = 1;
}
void insert(string d) 
{
    int e = 0;
    for(int i=0;i<d.size();i++)
    {
        int next = (d[i] == '.' ? 0 : 1);
        if(g[e][next] == -1) {
            g[e][next] = estados;
            for(int j=0;j<3;j++) g[estados][j] = -1;
            g[estados++][2] = 0;
        }
        e = g[e][next];
    }
    g[e][2]++;
}

void go(int idx)
{
    int e = 0;
    for(int i=idx;i<s.size();i++)
    {
        int next = (s[i] == '.' ? 0 : 1);
        e = g[e][next];
        if(e == -1) break;
        dp[i+1] += (dp[idx]*g[e][2]);
    }
}

string transform(string d)
{
    string r="";
    for(int i=0;i<d.size();i++) r += T[d[i]-'A'];
    return r;
}

int main()
{
    int t, n;
    cin >> t;
    while(t--)
    {
        string d;
        memset(dp,0,sizeof(dp));
        init();
        cin >> s;
        cin >> n;
        for(int i=0;i<n;i++) 
        {
            cin >> d;
            insert(transform(d));
            //cout << transform(d) << endl;
        }
        /*
        for(int i=0;i<estados;i++)
        {
            for(int j=0;j<3;j++) printf("%3d", g[i][j]);
            cout << endl;
        }
        */
        dp[0] = 1;
        for(int i=0;i<s.size();i++) go(i);
        /*
        for(int i=0;i<=s.size();i++) cout << dp[i] << " ";
        cout << endl;
        for(int i=0;i<=s.size();i++) cout << s[i] << " ";
        cout << endl;
        */
        cout << dp[s.size()] << endl;
        if(t) cout<<endl;
    }
    return 0;
}
