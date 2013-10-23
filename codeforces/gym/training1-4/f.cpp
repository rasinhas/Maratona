#include <iostream>
#include <string>
#include <cstdio>
#include <cstring>
#include <map>

using namespace std;

map <string,int> mi, pi;
map <string,int>::iterator im, ip;
string tb[111][111];

int main()
{
    int t, n;
    cin >> t;
    while(t--)
    {
        int mc=0, pc=0;
        cin >> n;
        mi.clear();
        pi.clear();
        while(n--)
        {
            int i, j;
            string m, p, c;
            cin >> m >> p >> c;
            while(m.size()<3) m+=" "; 
            while(p.size()<3) p+=" "; 
            while(c.size()<3) c+=" "; 
            if(mi.count(m)) i = mi[m];
            else 
            {
                mi[m] = mc;
                i = mc++;
            }
            if(pi.count(p)) j = pi[p];
            else 
            {
                pi[p] = pc;
                j = pc++;
            }
            tb[i][j] = c;
        }
        for(int j=0;j<=pi.size();j++) cout << "+---";
        cout << "+" << endl;
        cout << "|   ";
        for(ip = pi.begin();ip != pi.end(); ip++) cout << "|" << (ip->first);
        cout << "|" << endl;
        for(im = mi.begin();im != mi.end(); im++)
        {
            for(int j=0;j<=pi.size();j++) cout << "+---";
            cout << "+" << endl;
            cout << "|" << (im->first);
            for(ip = pi.begin();ip != pi.end(); ip++) 
            {
                string s=tb[im->second][ip->second];
                cout << "|" << (s != "" ? s : "   ");
            }
            cout << "|" << endl;
        }
        for(int j=0;j<=pi.size();j++) cout << "+---";
        cout << "+" << endl;
        for(int i=0;i<=mc;i++) for(int j=0;j<=pc;j++) tb[i][j] = "";
    }
    return 0;
}
