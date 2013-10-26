#include <iostream>
#include <cstdio>
#include <vector>

using namespace std;

int c[111111], t[3];
vector <int> zi;

int main()
{
    int n;
    cin >> n;
    for(int i=0;i<n;i++)
    {
        cin >> c[i];
        if(c[i] == 0) zi.push_back(i);
    }
    zi.push_back(n);
    int j=0;
    for(int i=0;i<zi.size();i++)
    {
        int m = 0, idx=0;
        for(int k=j;k<zi[i];k++) if(m < c[k])
        {
            m = c[k];
            idx = k;
        }
        for(;j<zi[i];j++)
        {
            if(j == idx) 
            {
                t[0] = c[idx];
                cout << "pushQueue" << endl;
            }
            else
            {
                if((c[j] > t[1] && t[2] >= t[1]))
                {
                    t[1] = c[j];
                    cout << "pushStack" << endl;
                }
                else if(c[j] > t[2])
                {
                    t[2] = c[j];
                    cout << "pushFront" << endl;
                }
                else cout << "pushBack" << endl;
            }
        }
        if(j == n) break;
        if(c[j] == 0)
        {
            int cnt=0, s=0;
            for(int k=0;k<3;k++) 
            {
                s += t[k];
                if(t[k] > 0) cnt |= (1<<k);
                t[k] = 0;
            }
            cout << (__builtin_popcount(cnt));
            if(cnt&1) cout << " popQueue";
            if(cnt&2) cout << " popStack";
            if(cnt&4) cout << " popFront";
            cout << endl;
            j++;
        }
    }
    return 0;
}
