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

pii a[1111];

int main()
{
    int n;
    while(scanf("%d", &n) && n) {
        for(int i=0;i<n;i++) {
            scanf("%d", &a[i].first);
            a[i].second = i+1;
        }
        sort(a,a+n);
        cout << a[n-2].second << endl;
    }
    return 0;
}
