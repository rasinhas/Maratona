#include <bits/stdc++.h>

using namespace std;

int a[222222], m[2] = {1111111,1111111};

int main() {
    int n;
    int s1=0, s2=11111111;
    cin >> n;
    for(int i=0;i<n;i++)  {
        scanf("%d", &a[i]);
        if(a[i] < m[1]) {
            m[1] = a[i];
            if(m[1] < m[0]) swap(m[0],m[1]);
        }
    }
    a[n] = 222222222;
    for(int i=1;i<n;i++) {
        int mm = (a[i]+1)/2;
        int ma = (a[i-1]+1)/2;
        int mb = (a[i+1]+1)/2;
        int r1, r2;
        if(ma < mb) {
            r1 = max(max(mm, ma),(a[i]+a[i-1]+2)/3);
        }
        else r1 = max(max(mm, mb),(a[i]+a[i+1]+2)/3);
        if(a[i-1] < a[i+1]) r2 = a[i-1] + (a[i+1]-a[i-1]+1)/2;
        else r2 = a[i+1] + (a[i-1]-a[i+1]+1)/2;
        s2 = min(s2,min(r1,r2));
    }
    s1 = (m[0]+1)/2 + (m[1]+1)/2;
    cout << min(s1,s2) << endl;
    return 0;
}
