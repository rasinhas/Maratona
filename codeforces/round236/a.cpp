#include <iostream>
#include <cstdio>

using namespace std;

int main() 
{
    int t;
    cin >> t;
    while(t--) {
        int n, m;
        cin >> n >> m;
        int e = 2*n + m;
        int d = 1, cur = 0;
        while(1) {
            if(!e) break;
            printf("%d %d\n", cur+1, ((cur+d)%n)+1);
            cur = cur + 1;
            e--;
            if(cur == n) {
                cur %= n;
                d++;
            }
        }
    }
    return 0;
}
