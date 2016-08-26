#include <iostream>
#include <cstdio>
#include <string>
#include <cstring>
#include <vector>
#include <map>
#include <algorithm>

using namespace std;

map <int,string> word;
map <string,int> id;
int show[1001][20001];
pair<int,int> top[20001];
vector<pair<int,string> > ans;

int main()
{
    int c = 0, d = 0;
    string s;
    while(cin>>s && !cin.eof())
    {
        if(s == "<text>")
        {
            while(cin>>s && s != "</text>")
            {
                if(s.size() < 4) continue;
                if(!id.count(s))
                {
                    id[s] = c;
                    word[c++] = s;
                }
                show[d][id[s]]++;
            }
            d++;
        }
        else
        {
            int n;
            cin >> n;
            cin >> s;
            for(int j=0;j<c;j++) top[j] = make_pair(0,j);
            for(int i=d;i>=max(d-7,0);i--) for(int j=0;j<c;j++) top[j].first -= show[i][j];
            sort(top,top+c);
            cout << "<top " << n << ">" << endl;
            int i=0;
            ans.clear();
            while(1)
            {
                if(n == 0 && top[i].first != top[i-1].first) break;
                n = max(0,n-1);
                if(top[i].first == 0) break;
                ans.push_back(make_pair(top[i].first,word[top[i].second]));
                i++;
            }
            sort(ans.begin(),ans.end());
            for(int j=0;j<ans.size();j++) cout << ans[j].second << " " << -ans[j].first << endl;
            cout << "</top>" << endl;
        }
    }
    return 0;
}
