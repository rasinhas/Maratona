#include <iostream>
#include <fstream>
#include <cstdio>
#include <string>
#include <cstring>
#include <algorithm>

using namespace std;

int main()
{
    ifstream in("jenga.in");
    int n, t;
    string w;
    in >> t;
    for(int i=0;i<t;i++)
    {
        in >> n;
        cout << "Case " << i+1 << ": " << (n%3 ? "Bakkar" : "Wahdan") << endl;
    }
    return 0;
}
