#include <iostream>
#include <cstdio>
#include <algorithm>
#include <vector>
#include <cstring>
#include <string>
#define ff first
#define ss second

using namespace std;

typedef long long ll;
typedef pair<int,int> pii;

char s[1111];
vector <string> st;

int main()
{
    int t, n;
    cin >> t;
    while(t--) {
        cin >> n;
        for(int i=0;i<n;i++) {
            getchar();
            scanf("%[^\n]", s);
            string str = s;
            st.push_back(str);
        }
        int r = 0;
        string cur = st[0];
        for(int i=1;i<n;i++) {
            if(st[i] < cur) r++;
            cur = max(cur,st[i]);
        }
        cout << r << endl;
        st.clear();
    }
    return 0;
}
