#include <stdio.h>
#include <vector>
#include <algorithm>
#include <string>
#include <iostream>
#include <cmath>
#define INF 1e9
#define EPS 1e-6


using namespace std;

double dist(double a, double b, double c, double d) { return hypot(a-c, b-d); }
    
int ord[7];
int njog[2];
vector<pair<double, double> > b(8);

int proximo() {
    int i;
    if(njog[0] == 3) return 1;
    if(njog[1] == 3) return 0;
    double dmin = INF;
    int prox;
    for(i=1;i<njog[0]+njog[1]+1;i++) {
        double d = dist(b[i].first, b[i].second, b[0].first, b[0].second);
        if(d < dmin) {
            dmin = d;
            prox = 1 - ord[i];
        }
    }
    return prox;
}

int main()
{
    int T, i, j;
    string nome[2];
    double x0, y0, teta, d, deltax, deltay, teta2;
    scanf("%d", &T);
    while(T--)
    {
        cin >> nome[0] >> nome[1];
        scanf("%lf%lf%lf%lf", &x0, &y0, &teta, &d);
        if(fabs(teta - 360) < EPS) teta = 0;
        teta = teta * 2 * acos(0) / 180;
        b[0] = make_pair(x0+d*cos(teta), y0+d*sin(teta));
        ord[0] = -1;
        scanf("%lf%lf%lf%lf", &x0, &y0, &teta, &d);
        if(fabs(teta - 360) < EPS) teta = 0;
        teta = teta * 2 * acos(0) / 180;
        ord[1] = 0;
        deltax = b[0].first - x0;
        deltay = b[0].second - y0;
        if(fabs(deltax) > 0) teta2 = tan(deltay / deltax);
        else if(deltay > EPS) teta2 = acos(0); 
        else teta2 = 3*acos(0);
        if(fabs(teta2 - teta) < EPS && dist(x0, y0, b[0].first, b[0].second) < d+EPS) {
            b[1] = b[0];
            b[0] = make_pair(x0+d*cos(teta), y0+d*sin(teta));
        }
        else b[1] = make_pair(x0+d*cos(teta), y0+d*sin(teta));
        njog[0] = 1;
        njog[1] = 0;
        for(i=2;i<7;i++) {
            scanf("%lf%lf%lf%lf", &x0, &y0, &teta, &d);
            if(fabs(teta - 360) < EPS) teta = 0.0;
            teta = teta * 2 * acos(0) / 180;
            if(i == 2) ord[i] = 1, njog[1]++;
            else {
                ord[i] = proximo();
                njog[ord[i]]++;
            }
            b[7] = make_pair(x0+d*cos(teta), y0+d*sin(teta));
            b[i] = make_pair(x0, y0);
            vector<pair<double, int> > v;
            v.push_back(make_pair(0.0, i));
            v.push_back(make_pair(d, 7));
            for(j=0;j<i;j++) {
                deltax = b[j].first - x0;
                deltay = b[j].second - y0;
                teta2 = atan2(deltay , deltax);
                if(teta2 < 0) teta2 += 4*acos(0);
                if(fabs(teta2 - teta) < EPS && dist(x0, y0, b[j].first, b[j].second) < d-EPS) {
                    v.push_back(make_pair(dist(x0, y0, b[j].first, b[j].second), j));
                }
            }
            sort(v.begin(), v.end());
            for(j=0;j<v.size()-1;j++) {
                b[v[j].second] = b[v[j+1].second];
            }
        }
        double mindist = INF;
        int v, p, pontos;
        for(i=1;i<7;i++) {
            double d = dist(b[i].first, b[i].second, b[0].first, b[0].second);
            if(d < mindist - EPS) {
                mindist = d;
                v = ord[i];
            }
        }
        p = 1 - v;
        pontos = 0;
        mindist = INF;
        for(i=1;i<7;i++) if(ord[i] == p) mindist = min(mindist, dist(b[i].first, b[i].second, b[0].first, b[0].second));
        for(i=1;i<7;i++) if(ord[i] == v) {
             if(dist(b[i].first, b[i].second, b[0].first, b[0].second) < mindist) pontos++;
        }
        cout << nome[v] << " " << pontos << endl;
    }
    return 0;
}
