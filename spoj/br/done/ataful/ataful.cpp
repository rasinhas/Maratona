#include <stdio.h>
#include <stdlib.h>
#include <algorithm>
#include <math.h>
#define PI 3.1415926537
#define EPS 1e-8

using namespace std;

int main()
{
    double x, y, r, p, q, a, t;
    double d, arad, trad, na, ti, tf, ai, af, s, argc, aux1, aux2;
    while(scanf("%d%d%d", &x, &y, &r) && (x || y || r))
    {
        scanf("%d%d%d%d", &p, &q, &a, &t);
        //colocar o canhão na origem//
        // -> (p,q) => (0,0) -> (a,b) => (a-p,b-q)
        //colocar a circunferencia no eixo x
        //arctg((y-q)/(x-p)) => 0 -> a => a-arctg((y-q)/(x-p))
        argc = atan2((y-q),(x-p));
        d = hypot((x-p),(y-q));
        arad = PI*a/180.0;
        trad = PI*t/180.0;
        na = arad - argc;
        if(na > PI) na = 2*PI - na;
        if(na < -PI) na = 2*PI + na;
        ti = na - trad/2; 
        tf = na + trad/2;
        if(ti > asin(r/d) && tf > asin(r/d) || tf < -asin(r/d) && ti < -asin(r/d)) s = 0.0;
        else
        {
            //clipar o ti e o tf para as tangentes a circunferencia
            ti = max(ti,-asin(r/d));
            tf = min(tf,asin(r/d));
            aux1=sin(ti)*d/r;
            aux2=sin(tf)*d/r;
            if(aux1>0) aux1-=EPS;
            else aux1+=EPS;
            if(aux2>0) aux2-=EPS;
            else aux2+=EPS;
            ai = asin(aux1);
            af = asin(aux2);
            //printf("%lf %lf %lf %lf\n", sin(ti)*d/r, sin(tf)*d/r, ai, af);
            //valor da integral => 2*r*r*(a/2+sen(2*a))[(intervalo)
            //onde t = r*sen(a)/d -> t é o angulo com o eixo x
            //e d é a distancia do canhão ao centro da circunferencia
            s = r*r*(af+sin(2*af)/2 - ai-sin(2*ai)/2);
        }
        printf("%.1lf\n", s);
    }
    return 0;
}
