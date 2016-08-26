#include <bits/stdc++.h>

using namespace std;

long long p5[33], p2[63];

int main() {
    int T;
    cin >> T;
    p5[0] = p2[0] = 1;
    for(int i=1;i<30;i++) p5[i] = p5[i-1]*5;
    for(int i=1;i<60;i++) p2[i] = p2[i-1]*2;
    for(int t=1;t<=T;t++) {
        int n;
        char a;
        string s;
        scanf("%d[", &n);
        a = getchar();
        while(a != ']') {
            s += a;
            a = getchar();
        }
        if(s == "B") n = 0;
        if(s == "KB") n = 1;
        if(s == "MB") n = 2;
        if(s == "GB") n = 3;
        if(s == "TB") n = 4;
        if(s == "PB") n = 5;
        if(s == "EB") n = 6;
        if(s == "ZB") n = 7;
        if(s == "YB") n = 8;
        printf("Case #%d: %.2lf%%\n", t, 100*(1.0-(1.0*p5[3*n])/(1.0*p2[7*n])));
    }
}
