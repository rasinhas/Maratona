#include <iostream>
#include <cstdio>
#include <cstring>
#include <string>
#include <algorithm>
#include <vector>

using namespace std;
typedef pair<int,int> pt;

pt b[111111];
vector <string> s;

int mod(int a) { return a > 0 ? a : -a; }

bool cmp(pt a, pt b) { return (mod(a.first)+mod(a.second)) < mod(b.first)+mod(b.second); }

int main()
{
    int n;
    cin >> n;
    for(int i=0;i<n;i++) cin >> b[i].first >> b[i].second;
    sort(b,b+n,cmp);
    int m = 0;
    string a;
    char c[11];
    for(int i=0;i<n;i++)
    {
        if(b[i].first != 0)
        {
            m++;
            a = "1 ";
            sprintf(c,"%d",mod(b[i].first));
            a += c;
            if(b[i].first > 0) a += " R";
            else a += " L";
            s.push_back(a);
        }
        if(b[i].second != 0)
        {
            m++;
            a = "1 ";
            sprintf(c,"%d",mod(b[i].second));
            a += c;
            if(b[i].second > 0) a += " U";
            else a += " D";
            s.push_back(a);
        }
        m++;
        s.push_back("2");
        if(b[i].first != 0)
        {
            m++;
            a = "1 ";
            sprintf(c,"%d",mod(b[i].first));
            a += c;
            if(b[i].first > 0) a += " L";
            else a += " R";
            s.push_back(a);
        }
        if(b[i].second != 0)
        {
            m++;
            a = "1 ";
            sprintf(c,"%d",mod(b[i].second));
            a += c;
            if(b[i].second > 0) a += " D";
            else a += " U";
            s.push_back(a);
        }
        m++;
        s.push_back("3");
    }
    cout << m << endl;
    for(int i=0;i<s.size();i++) cout << s[i] << endl;
    return 0;
}
