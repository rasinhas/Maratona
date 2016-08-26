#include <iostream>
#include <cstdio>

using namespace std;

int main()
{
    // até 0 -> 1 par
    // até 1 -> 2 pares
    // até 2 -> 3 pares
    // até 3 -> 4 pares
    // até 4 -> 5 pares
    // até 9 -> 5 pares
    // até 14 -> 10 pares
    // até 19 -> 10 pares
    // até 24 -> 15 pares
    // até 49 -> 30 pares
    // até 74 -> 45 pares
    // até 99 -> 60 pares
    // até 124 -> 75 pares
    // até 249 -> 125 pares
    // até 374 -> 175 pares
    // até 499 -> 225 pares
    // até 624 -> 275 pares
    // até 1249 -> 550 pares

    // 1000 = 5^4 + 3*5^3 -> 376+225
    long long n;
    while(cin >> n && n != -1)
    {
        int k = n%10;
        int r = (n-n%10)/2;
        cout << r+e[k] << endl;
    }
    return 0;
}
