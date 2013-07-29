#include <cstdio>
#include <iostream>
#include <map>
#include <string>
#include <cstring>

using namespace std;

map <string,int> m;
map <int, string> id;
map <int, string>::iterator it;
char line[1111], rob[111];

int main()
{
    int n, t, l;
    cin >> t;
    for(int i=1;i<=t;i++)
    {
        string s;
        string lf;
        printf("Test set %d:\n", i);
        cin >> n;
        for(int j=0;j<n;j++)
        {
            cin >> s;
            m[s] = 0;
            id[j] = s;
        }
        cin >> l;
        for(int j=0;j<l;j++)
        {
            getchar();
            scanf("%[^\n]", line);
            s = "";
            while(1)
            {
                sscanf(line,"%s %[^\n]", rob, line);
                s = rob;
                if(m.count(s)) m[s]++;
                if(line == lf) break;
                lf = line;
            }
        }
        for(it=id.begin();it!=id.end();it++)
        {
            if(m[it->second]) cout << it->second << " is present" << endl;
            else cout << it->second << " is absent" << endl;
        }
        cout << endl;
        m.clear();
        id.clear();
    }
    return 0;
}
