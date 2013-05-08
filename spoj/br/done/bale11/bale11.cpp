#include <iostream>
#include <algorithm>
#include <vector>
#include <map>
#include <set>
#include <queue>
#include <stack>
#include <string>
#include <utility>
#include <stdio.h>
#include <string.h>
#define INF 0x3f3f3f3f
#define rep(i,n) for(i=0;i<(n);i++)

using namespace std;

int cnt=0;
vector <int> a;

void merge(int p, int q, int r)
{
    vector <int> left, right;
    int i, j=0, k=0;
    int n, m, lenl;
    n=q-p+1;
    m=r-q;
    for(i=1;i<=n;i++) left.push_back(a[p+i-1]); 
    for(i=1;i<=m;i++) right.push_back(a[q+i]); 
    left.push_back(INF);
    right.push_back(INF);
    lenl=left.size();
    for(i=p;i<=r;i++)
    {
        if(left[j]<=right[k])
        {
            a[i]=left[j];
            j++;
        }
        else
        {
            a[i]=right[k];
            cnt+=(lenl-j-1);
            k++;
        }
    }
}

void merge_sort(int p, int r)
{
    int q;
    if(p<r)
    {
        q=(p+r)/2;
        merge_sort(p,q);
        merge_sort(q+1,r);
        merge(p,q,r);
    }
}

int main()
{
    int i, b, n;
    scanf("%d",&n);
    for(i=0;i<n;i++)
    {
        scanf("%d", &b);
        a.push_back(b);
    }
    merge_sort(0,n-1);
    printf("%d\n", cnt);
	return 0;
}
