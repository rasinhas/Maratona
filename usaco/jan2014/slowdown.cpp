#include <iostream>
#include <cstdio>
#include <fstream>
#include <algorithm>
#include <cmath>
#include <vector>

using namespace std;

vector<double> tim, dist;

int main()
{
    ifstream in("slowdown.in");
    ofstream out("slowdown.out");
    int n, t;
    double tt=0, dt=0, tpm=1.0;
    char s;
    in >> n;
    for(int i=0;i<n;i++)
    {
        in >> s >> t;
        if(s == 'T') tim.push_back(t);
        else if(s == 'D') dist.push_back(t);
    }
    dist.push_back(1000);
    tim.push_back(1000000000);
    sort(tim.begin(),tim.end());
    sort(dist.begin(),dist.end());
    int dp=0, tp=0;
    for(int i=0;i<n+1;i++)
    {
        if((tim[tp]-tt) <= (dist[dp]-dt)*tpm)
        {
            dt += ((tim[tp]-tt)/tpm);
            tt = tim[tp];
            tp++;
        }
        else
        {
            tt += ((dist[dp]-dt)*tpm);
            dt = dist[dp];
            dp++;
        }
        tpm++;
    }
    out << (int)(tt+fmod(tt,1)) << endl;
    return 0;
}

