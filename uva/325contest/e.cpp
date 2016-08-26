#include <iostream>
#include <cstdio>
#include <cstring>
#include <string>
#include <vector>

using namespace std;

bool canConv(string a, string b)
{
    int ac[33], bc[33];
    for(int i=0;i<33;i++) ac[i] = bc[i] = 0;
    if(a.size() != b.size()) return 0;
    else if(a[0] != b[0] || a[a.size()-1] != b[b.size()-1]) return 0;
    else
    {
        for(int i=0;i<a.size();i++)
        {
            ac[a[i]-'a']++;
            bc[b[i]-'a']++;
        }
        for(int i=0;i<30;i++) if(ac[i] != bc[i]) return 0;
        return 1;
    }
    return 0;
}

int main()
{
    int n;
    char s[2222], *t;
    string d[2222], p, ret;
    cin >> n;
    getchar();
    while(n--)
    {
        int i=0;
        scanf("%[^\n]", s);
        getchar();
        t = strtok(s," ");
        while(t != NULL)
        {
            d[i] = t;
            t = strtok(NULL," ");
            i++;
        }
        scanf("%[^\n]", s);
        getchar();
        t = strtok(s," ");
        int k=0;
        while(t != NULL)
        {
            string r="";
            p = t;
            for(int j=0;j<i;j++) if(canConv(p,d[j]))
            {
                r = d[j];
                break;
            }
            if(k != 0) cout << " ";
            if(r == "") cout << p;
            else cout << r;
            t = strtok(NULL," ");
            k++;
        }
        cout << endl;
    }
    return 0;
}
