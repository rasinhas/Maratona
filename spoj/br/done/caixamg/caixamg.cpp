#include <bits/stdc++.h>

using namespace std;

double y, z;

double f(double x) {
    return x*(y-2*x)*(z-2*x);
}

int main() {
    while(scanf("%lf%lf", &y, &z) && y) {
        double a = 12, b = -4*(y+z), c = y*z;
        double delta = b*b - 4*a*c;
        double x = (-b - sqrt(delta))/(2*a);
        printf("%.4lf %.4lf\n", x, f(x));
    }
    return 0;
}
