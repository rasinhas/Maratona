#include <iostream>
#include <cstdio>
#include <cstring>
#define MOD 1000000007

using namespace std;

int m[10] = {0, 1, 3, 6, 10, 15, 21, 28, 36, 45};

int main()
{
    int n;
    long long ret;
    string s, w;
    long long mai[100100], men[100100];
    scanf("%d", &n);
    memset(mai,0,(n+1)*sizeof(long long));
    memset(men,0,(n+1)*sizeof(long long));
    cin >> s;
    cin >> w;
    for(int i=0;i<n;i++)
    {
        if(s[i] == '?')
        {
            if(w[i] == '?') mai[i] = mai[i-1] + 45;
            else mai[i] = mai[i-1] + m['9'-w[i]];
        }
        else
        {
            if(w[i] == '?') mai[i] = mai[i-1] + m[s[i]-'0'];
            else if(s[i] > w[i]) mai[i] = mai[i-1]+ 1; 
            else mai[i] = mai[i-1];
        }
    }
    for(int i=n-1;i>=0;i--)
    {
        if(s[i] == '?')
        {
            if(w[i] == '?') men[i] = men[i+1] + 45;
            else men[i] = men[i+1] + m['9'-w[i]];
        }
        else
        {
            if(w[i] == '?') men[i] = men[i+1] + m[s[i]-'0'];
            else if(s[i] < w[i]) men[i] = men[i+1] + 1; 
            else men[i] = men[i+1];
        }
    }
    ret = 0;
    for(int i=0;i<n-1;i++)
    {
        ret = (ret+(mai[i]*men[i+1]))%MOD;
    }
    cout << ret << endl;
    for(int i=0;i<n;i++) cout << mai[i] << " ";
    cout << endl;
    for(int i=0;i<n;i++) cout << men[i] << " ";
    cout << endl;
    return 0;
}
