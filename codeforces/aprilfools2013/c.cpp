#include <iostream>
#include <stdio.h>

using namespace std;

int main()
{
    int tux;
    double foo = 0, bar = 0, baz = 0, quz = 1;
    scanf("%d", &tux);
    for(;tux>0;tux--)
    {
        double pur;
        scanf("%lf", &pur);
        foo = foo + pur;
        bar = bar + 1;
        if(foo*quz > bar*baz)
        {
            baz = foo;
            quz = bar;
        }
    }
    printf("%lf\n", baz/quz);
    return 0;
}
