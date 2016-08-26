#include <bits/stdc++.h>
using namespace std;

struct pt {
    int x, y;
    pt(int x=0, int y=0): x(x), y(y) {}
    int operator %(pt p) { return x*p.y - y*p.x; }
};

int area(pt a, pt b, pt c) { return abs((b%c - a%c + a%b)); }

int main() {
    int t;
    pt p[5];
    scanf("%d", &t);
    while(t--) {
        for(int i=0; i<4; i++) scanf("%d %d", &p[i].x, &p[i].y);
        scanf("%d %d", &p[4].x, &p[4].y);
        if(area(p[4], p[0], p[1])+area(p[4], p[1], p[2])+
                area(p[4], p[2], p[3])+area(p[4], p[0], p[3])==
                area(p[0], p[1], p[2])+area(p[0], p[2], p[3])) printf("1\n");
        else printf("0\n");
    }
    return 0;
}
