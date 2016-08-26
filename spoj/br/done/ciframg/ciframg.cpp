#include <bits/stdc++.h>

using namespace std;

int a[4444444];
int m[1111111];
int n;
const int N = 1e6;

int query(int idx)
{
    if(idx == 0) return 0;
    int sum=0;
    while(idx <= N)
    {
        sum += m[idx];
        idx += (idx & -idx);
    }
    return sum;
}

void update(int idx, int val)
{
    while(idx > 0)
    {
        m[idx]+=val;
        idx -= (idx & -idx);
    }
}


int main() {
    while(scanf("%d", &n) && n) {
        for(int i=0;i<n;i++) scanf("%d", &a[i]);
        int i = 0;
        memset(m,0,sizeof(m));
        printf("MENSAGEM: [");
        while(1) {
            if(a[i] == 18) {
                update(a[i+1], -a[i+3]);
                update(a[i+2]+1, a[i+3]);
                i += 4;
            }
            else if(a[i] == 42) {
                int v = query(a[i+1]+1)-query(a[i+1]);
                if(v < 0) printf(" ");
                else printf("%c", 'A'+v%26);
                i += 2;
            }
            else if(a[i] == 0) break;
        }
        printf("]\n");
    }
    return 0;
}
