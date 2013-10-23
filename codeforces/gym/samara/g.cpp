#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>

using namespace std;

vector <int> sq;

int main()
{
    int n;
    cin >> n;
    for(int i=0;i*i<=n;i++) sq.push_back(i*i);
    for(int i=0;i<sq.size();i++) 
    {
        if(binary_search(sq.begin(),sq.end(),n-sq[i]))
        {
            cout << "YES" << endl;
            return 0;
        }
    }
    cout << "NO" << endl;
    return 0;
}
