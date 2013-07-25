#include <iostream>
#include <cstdio>
#include <string>
#include <map>
#include <queue>

using namespace std;

//map <string,int> m;
string magic[8] = {"276951438", "492357816", "834159672", "618753294", "672159834", "816357492", "438951276", "294753618"};
int fat[10]={1,1,2,6,24,120,720,5040,40320,362880};
int vis[444444];

string counter(string s, int p)
{
    swap(s[p],s[p+1]);
    swap(s[p+1],s[p+4]);
    swap(s[p+4],s[p+3]);
    return s;
}
string clock(string s, int p)
{
    swap(s[p+4],s[p+3]);
    swap(s[p+1],s[p+4]);
    swap(s[p],s[p+1]);
    return s;
}
int lex(string s)
{
    int ret=0;
    for(int i=0;i<s.size();i++)
    {
        int k=0;
        for(int j=i+1;j<s.size();j++)
        {
            if(s[j] < s[i]) k++;
        }
        ret += fat[s.size()-i-1]*k;
    }
    return ret;
}
void bfs()
{
    queue <string> q;
    for(int i=0;i<8;i++)
    {
        q.push(magic[i]);
        vis[lex(magic[i])] = 1;
    }
    while(!q.empty())
    {
        string u = q.front();
        int l = lex(u);
        q.pop();
        for(int i=0;i<5;i++) if(i!=2) 
        {
            string s = counter(u,i);
            int v = lex(s);
            if(!vis[v])
            {
                vis[v] = vis[l]+1;
                q.push(s);
            }
        }
        for(int i=0;i<5;i++) if(i!=2) 
        {
            string s = clock(u,i);
            int v = lex(s);
            if(!vis[v])
            {
                vis[v] = vis[l]+1;
                q.push(s);
            }
        }
    }
}

int main()
{
    string s;
    bfs();
    while((cin >> s) && s != "END")
    {
        cout << vis[lex(s)]-1 << " moves" << endl;
    }
    return 0;
}
