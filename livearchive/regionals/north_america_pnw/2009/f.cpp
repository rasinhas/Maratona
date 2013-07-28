#include <iostream>
#include <cstdio>

using namespace std;

int r[55], inv[55];
int n;

void clockwise()
{
    int aux[55];
    for(int i=0;i<n;i++) inv[r[i]] = i;
    for(int i=0;i<n;i++) r[i] = n-1-inv[i];
}

void mirror()
{
    for(int i=0;i<n;i++) r[i] = n-1-r[i];
}

void print()
{
    for(int i=0;i<n;i++) printf("%3d", r[i]);
    cout << endl;
}

int main()
{
    while((cin >> n) && n)
    {
        for(int i=0;i<n;i++) cin >> r[i];
        for(int i=0;i<4;i++)
        {
            print();
            clockwise();
        }
        mirror();
        for(int i=0;i<4;i++)
        {
            print();
            clockwise();
        }
        cout << endl;
    }
    return 0;
}
