#include <iostream>
#include <cstdio>
#include <algorithm>
#include <vector>
#include <cstring>
#include <string>
#define ff first
#define ss second

using namespace std;

typedef long long ll;
typedef pair<int,int> pii;

int main()
{
    int t;
    scanf("%d", &t);
    while(t--) {
        int a1, a2, b1, b2;
        scanf("%d x %d", &a1, &a2);
        scanf("%d x %d", &b2, &b1);
        if(a1+b1 > a2+b2) cout << "Time 1" << endl;
        else if (a1+b1 < a2+b2) cout << "Time 2" << endl;
        else {
            if(a1 == b2) cout << "Penaltis" << endl;
            else {
                if(b1 > a2) cout << "Time 1" << endl;
                else cout << "Time 2" << endl;
            }
        }
    }
    return 0;
}
