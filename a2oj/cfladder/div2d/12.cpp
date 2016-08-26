#include <stdio.h>
#include <algorithm>
#include <cmath>
#include <iostream>
#include <utility>
#define INF 0x3f3f3f3f
#define EPS 1e-6

using namespace std;

int a[6];

int main() {
    int vx, vy, vz, tx, ty, tz;
    cin >> vx >> vy >> vz;
    cin >> tx >> ty >> tz;
    for(int i=0;i<6;i++) cin >> a[i];
    int r = 0;
    if(vy < 0) r += a[0];
    if(vz < 0) r += a[2];
    if(vx < 0) r += a[4];
    if(vy > ty) r += a[1];
    if(vz > tz) r += a[3];
    if(vx > tx) r += a[5];
    cout << r << endl;
    return 0;
}
