#include <iostream>
#include <cstdio>
#include <algorithm>
#include <string>
#include <cstring>
#include <set>

using namespace std;

int tree[111111], l[111111], r[111111], isStand[111111], isLeft[111111];
set <int> st;
string s;
int n;

int read(int idx)
{
    int sum=0;
    while(idx > 0)
    {
        sum += tree[idx];
        idx -= (idx & -idx);
    }
    return sum;
}

void update(int idx, int val)
{
    while(idx<=n)
    {
        tree[idx]+=val;
        idx+=(idx & -idx);
    }
}

int main()
{
    int t, q;
    cin >> t;
    while(t--)
    {
        cin >> n >> q >> s;
        memset(tree,0,sizeof(tree));
        st.clear();
        st.insert(0);
        st.insert(n+1);
        isLeft[0] = isStand[0] = isStand[n+1] = 1;
        isLeft[n+1] = 0;
        for(int i=1;i<=n;i++)
        {
            l[i] = i-1;
            r[i] = i+1;
            if(s[i-1] == '<') isLeft[i] = 1;
            else isLeft[i] = 0;
            isStand[i] = 1;
            if(i > 1 && isLeft[i] == 1 && isLeft[i-1] == 0) update(i,1);
            st.insert(i);
        }
        int p, i, j;
        while(q--)
        {
            cin >> p;
            if(p == 1)
            {
                cin >> i;
                if(isStand[i])
                {
                    l[r[i]] = l[i];
                    r[l[i]] = r[i];
                    st.erase(i);
                    if(isLeft[i] == 1 && isLeft[l[i]] == 0) update(i,-1);
                    else if(isLeft[i] == 0 && isLeft[r[i]] == 1) update(r[i],-1);
                    if(isLeft[r[i]] == 1 && isLeft[l[i]] == 0) update(r[i],1);
                }
                else
                {
                    set <int>::iterator it;
                    it = st.upper_bound(i);
                    r[i] = (*it--);
                    l[i] = (*it);
                    l[r[i]] = i;
                    r[l[i]] = i;
                    st.insert(i);
                    if(isLeft[r[i]] == 1 && isLeft[l[i]] == 0) update(r[i],-1);
                    if(isLeft[i] == 1 && isLeft[l[i]] == 0) update(i,1);
                    else if(isLeft[i] == 0 && isLeft[r[i]] == 1) update(r[i],1);
                }
                isStand[i] ^= 1;
            }
            else if(p == 2)
            {
                cin >> i;
                if(isLeft[i] == 1 && isLeft[l[i]] == 0 && isStand[i]&isStand[l[i]] == 1) update(i,-1);
                else if(isLeft[i] == 0 && isLeft[r[i]] == 1 && isStand[i]&isStand[r[i]] == 1) update(r[i],-1);
                if(isLeft[i] == 0 && isLeft[l[i]] == 0 && isStand[i]&isStand[l[i]] == 1) update(i,1);
                else if(isLeft[i] == 1 && isLeft[r[i]] == 1 && isStand[i]&isStand[r[i]] == 1) update(r[i],1);
                isLeft[i] ^= 1;
            }
            else 
            {
                cin >> i >> j;
                int ret = read(j)-read(i-1);
                int lim = *st.lower_bound(i);
                if(lim <= j && (read(lim)-read(lim-1)) == 1 && l[lim] < i) ret--;
                cout << ret << endl;
            }
        }
    }
    return 0;
}
