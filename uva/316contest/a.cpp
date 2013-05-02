#include <iostream>
#include <cstdio>
#include <string>

using namespace std;

int main()
{
    int n, v;
    string p;
    scanf("%d", &n);
    for(int i=0;i<n;i++)
    {
        cin >> p;
        v = (p[0]-'A')*26*26 + (p[1]-'A')*26 + (p[2] - 'A');
        v = v - (p[4]-'0')*1000 - (p[5]-'0')*100 - (p[6]-'0')*10 - (p[7]-'0');
        if(v <= 100 && v >= -100) printf("nice\n");
        else printf("not nice\n");
    }
    return 0;
}
