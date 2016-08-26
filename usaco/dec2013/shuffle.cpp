#include <iostream>
#include <cstdio>
#include <fstream>
#include <string>
#include <cstring>
#include <vector>
#include <queue>
#define ff first
#define ss second

using namespace std;

int k[111111];

int main()
{
    int n, m, q, p;
    ifstream in("shuffle.in");
    ofstream out("shuffle.out");
    in >> n >> m >> q;
    for(int i=0;i<m;i++) in >> k[i];
    for(int i=0;i<q;i++)
    {
        in >> p;
    }
    return 0;
}
