#include <iostream>
#include <cstdio>
#include <cstring>
#include <string>
#include <algorithm>
#define EPS 1e-6

using namespace std;

double mod(double a) { return a > -EPS ? a : -a; }

class TheArithmeticProgression {

    public:
    double minimumChange(int a, int b, int c)
    {
        double ret = 111111;
        double x[3] = {(double)a,(double)b,(double)c};
        ret = min(ret,mod(2*x[1]-x[0]-x[2])/2);
        ret = min(ret,mod(x[0]+x[2]-2*x[1])/2);
        return ret;
    }
};
